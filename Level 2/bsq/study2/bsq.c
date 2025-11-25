/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:18:47 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/25 15:11:31 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//load and check all elements
int	loadElement(FILE* file, t_elements *e)
{
	int result = fscanf(file, "%d %c %c %c", &e->n_lines, &e->empty, 
		&e->obstacle, &e->full);
	if (result != 4)
		return (-1);
	if (e->n_lines <= 0)
		return (-1);
	if (e->empty == e->obstacle || e->empty == e->full || e->obstacle == e->full)
		return (-1);
	if (e->empty < 32 || e->empty > 126)
		return (-1);
	if (e->full < 32 || e->full > 126)
		return (-1);
	if (e->obstacle < 32 || e->obstacle > 126)
		return (-1);
	return (0);
}

void	free_map(char** arr)
{
	if (arr)
	{
		for (int i = 0; arr[i]; i++)
			if(arr[i])
				free(arr[i]);
		free(arr);
	}
}

int		element_control(char **map, char c1, char c2)
{
	for (int i = 0; map[i]; i++)
		for(int j = 0; map[i][j]; j++)
			if ((map[i][j] != c1) && (map[i][j] != c2))
				return (-1);
	return (0);
}

char*	ft_substr(char* arr, int start, int len)
{
	int i = 0;
	int j = 0;
	char* newstr = (char*)malloc(len + 1);
	if (!newstr)
		return (NULL);
	while(arr[i])
	{
		if (j < len && start <= i)
		{
			newstr[j] = arr[i];
			j++;
		}
		i++;
	}
	newstr[j] = '\0';
	return newstr;
}

//read map
//skip \n
//store width and check same or not
int	loadMap(FILE* file, t_elements *element, t_maps *map, t_square *square)
{
	map->height = element->n_lines;
	map->grid = (char **)malloc((map->height + 1) * sizeof(char *));
	map->grid[map->height] = NULL;
	char	*lineptr = NULL;
	size_t	len = 0;

	//skip first line
	if (getline(&lineptr, &len, file) == -1)
	{
		free_map(map->grid);
		return -1;
	}
	for (int i = 0; i < map->height; i++)
	{
		int read = getline(&lineptr, &len, file);
		if (read == -1)
		{
			free(lineptr);
			free_map(map->grid);
			return -1;
		}
		if (lineptr[read - 1] == '\n')
			read--;
		else
		{
			free(lineptr);
			free_map(map->grid);
			return(-1);
		}
		map->grid[i] = ft_substr(lineptr, 0, read);
		if(!(map->grid[i]))
		{
			free(lineptr);
			free_map(map->grid);
			return (-1);
		}
		if(i == 0)
			map->width = read;
		else
		{
			if (map->width != read)
			{
				free(lineptr);
				free_map(map->grid);
				return -1;
			}
		}
	}
	if (element_control(map->grid, element->empty, element->obstacle) == -1)
	{
		free(lineptr);
		free_map(map->grid);
		return -1;
	}
	free (lineptr);
	return (0);
}

int	find_min(int n1, int n2, int n3)
{
	int min = n1;

	if (min > n2)
		min = n2;
	if (min > n3)
		min = n3;
	return min;
}

void	find_big_square(t_maps* map, t_elements* element, t_square* square)
{
	int matrix[map->height][map->width];
	for(int i = 0; i < map->height; i++)
		for(int j = 0; j < map->width; j++)
			matrix[i][j] = 0;
	for (int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
		{
			if(map->grid[i][j] == element->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int min = find_min(matrix[i - 1][j], matrix[i - 1][j -1], matrix[i][j - 1]);
				matrix[i][j] = min + 1;
			}
			
			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->y = i - matrix[i][j] + 1;
				square->x = j - matrix[i][j] + 1;
			}
		}
	}
}

void	print_filled_square(t_maps* map, t_square* square, t_elements* element)
{
	for (int i = square->y; i < square->y + square->size; i++)
		for (int j = square->x; j < square->x + square->size; j++)
			if (i < map->height && j < map->width)
				map->grid[i][j] = element->full;
	for(int i = 0; i < map->height; i++)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}
}

//load element
//load map
//find biggest suare
//print the map
int	execute_bsq(FILE* file)
{
	t_elements	element;
	t_maps		map;
	t_square	square;
	
	if (loadElement(file, &element))
		return (-1);
	if (loadMap(file, &element, &map, &square))
		return (-1);
	square.size = 0; square.x = 0; square.y = 0; 
	find_big_square(&map, &element, &square);
	print_filled_square(&map, &square, &element);
	free_map(map.grid);
	return (0);
}

//filename to filepointer
//execute bsq
int	convert_fileptr(char *filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
		return (-1);
	int ret = 0;
	ret = execute_bsq(file);
	fclose(file);
	return (ret);
}
