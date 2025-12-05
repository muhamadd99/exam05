/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:09:05 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/05 15:00:07 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//check all cases
int	loadElements(FILE* file, t_elements *elem)
{
	int ret = fscanf(file, "%d %c %c %c", &elem->n_lines, &elem->empty, 
				&elem->obstacle, &elem->full);

	if (ret != 4)
		return (-1);
	if (elem->n_lines <= 0)
		return (-1);
	if (elem->empty == elem->obstacle || elem->empty == elem->full || 
		elem->obstacle == elem->full)
		return (-1);
	if (elem->empty < 32 || elem->empty > 126)
		return (-1);
	if (elem->obstacle < 32 || elem->obstacle > 126)
		return (-1);
	if (elem->full < 32 || elem->full > 126)
		return (-1);
	return (0);
}

char	*ft_substr(char* arr, int start, int len)
{
	char	*newstr = (char *)malloc(len + 1);
	if (!newstr)
		return (NULL);
	int		i = 0;
	int		j = 0;
	while (arr[i])
	{
		if (start <= i && j < len)
		{
			newstr[j] = arr[i];
			j++;
		}
		i++;
	}
	newstr[j] = '\0';
	return newstr;
}

void	free_map(char **arr)
{
	int i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

//iterate map to check not correct char
int		element_control(char **map, char c1, char c2)
{
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j] != '\0')
		{
			if ((map[i][j] != c1) && (map[i][j] != c2))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

//declare height
//declare grid
//get 1st line
//a loop of getline, remove newline, substr, register/check map width
//element control
int		loadMaps(FILE* file, t_maps* map, t_elements* elements)
{
	map->height = elements->n_lines;
	map->grid = (char**)malloc(sizeof(char *) * (map->height + 1));
	map->grid[map->height] = NULL;
	
	char*	line = NULL;
	size_t	len  = 0;

	if (getline(&line, &len, file) == -1)
	{
		free_map(map->grid);
		return -1;
	}

	for (int i = 0; i < map->height; i++)
	{
		int read = getline(&line, &len, file);
		if(read == -1)
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		if (line[read - 1] == '\n')
			read--;
		else
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		map->grid[i] = ft_substr(line, 0, read);
		if (!(map->grid[i]))
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		
		if (i == 0)
			map->width = read;
		else
		{
			if (map->width != read)
			{
				free(line);
				free_map(map->grid);
				return (-1);
			}
		}
		
		if (element_control(map->grid, elements->empty, elements->obstacle) == -1)
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
	}
	free(line);
	return (0);
}

int find_min(int n1, int n2, int n3)
{
	int min = n1;
	if (min > n2)
		min = n2;
	if (min > n3)
		min = n3;
	return min;
}

void	find_biggest_square(t_maps* map, t_square* square, t_elements* elements)
{
	//matrix init
	int matrix[map->height][map->width];
	//loop to read map grid.
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			//check obstacle - matrix is 0.
			if (map->grid[i][j] == elements->obstacle)
				matrix[i][j] = 0;
			//check border matrix is 1.
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			//calculate using algo
			else
			{
				int min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
				matrix[i][j] = min + 1;
			}
			if (matrix[i][j] > square->size)
			//if algo updated the numbers, change the values
			{
				square->size = matrix[i][j];
				square->i = i - matrix[i][j] + 1;
				square->j = j - matrix[i][j] + 1;
			}
		}
	}
}

void	print_square(t_maps* map, t_square* square, t_elements* elements)
{
	//only modify the squares
	for (int i = square->i; i < square->i + square->size; i++)
	{
		for (int j = square->j; j < square->j + square->size; j++)
		{
			if ((i < map->height) && (j < map->width))
				map->grid[i][j] = elements->full;
		}
	}
	
	//print line by line
	for (int i = 0; i < map->height; i++)
	{
		fputs(map->grid[i], stdout);
		fputc('\n', stdout);
	}
}

//load elements
//load maps
//find biggest square
//free maps
int	execute_bsq(FILE *file)
{
	t_elements	elem;
	if (loadElements(file, &elem) == -1)
		return 1;
	t_maps		map;
	if (loadMaps(file, &map, &elem) == -1)
		return 1;
	t_square	square;
	square.size = 0; square.i = 0; square.j = 0;
	find_biggest_square(&map, &square, &elem);
	print_square(&map, &square, &elem);
	free_map(map.grid);
	return (0);
}

//open file
//give file pointer to execute bsq
int	convert_fileptr(char *name)
{
	FILE* file = fopen(name, "r");
	if (!file)
		return (-1);
	int ret = 0;
	ret = execute_bsq(file);
	fclose(file);
	return ret;
}