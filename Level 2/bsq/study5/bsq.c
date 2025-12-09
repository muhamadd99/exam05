/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:30:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/07 18:40:43 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	loadElements(FILE* file, t_element *elem)
{
	int ret = fscanf(file, "%d %c %c %c", &elem->nlines, &elem->empty, 
		&elem->obstacle, &elem->full);
	if (ret != 4)
		return -1;
	if (elem->nlines <= 0)
		return (-1);
	if (elem->empty == elem->obstacle || elem->obstacle == elem->full || 
		elem->full == elem->empty)
		return (-1);
	if (elem->empty < 32 || elem->empty > 126)
		return (-1);
	if (elem->obstacle < 32 || elem->obstacle > 126)
		return (-1);
	if (elem->full < 32 || elem->full > 126)
		return (-1);
	return (0);
}

char*	ft_substr(char* arr, int start, int len)
{
	int 	i = 0;
	int 	j = 0;
	char	*newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	
	if (arr)
	{
		while (arr[i])
		{
			if (i >= start && j < len)
			{
				newstr[j] = arr[i];
				j++;
			}
			i++;
		}
	}
	newstr[j] = '\0';
	return (newstr);
}

int		element_control(char** map, char c1, char c2)
{
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] != c1 && map[i][j] != c2)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_map(char** arr)
{
	if (arr)
	{
		for (int i = 0; arr[i]; i++)
		{
			if (arr[i])
				free(arr[i]);
		}
		free(arr);
	}
}

int loadMap(FILE *file, t_element* elem, t_map* map)
{
	//declare array
	map->height = elem->nlines;
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	map->grid[map->height] = NULL;
	char*	line = NULL;
	size_t	len = 0;
	//read from file
	if (getline(&line, &len, file) == -1)
	{
		free_map(map->grid);
		return (-1);
	}
	for (int i = 0; i < map->height; i++)
	{
		//
		int read = getline(&line, &len, file);
		if (read == -1)
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//remove newline and check
		if (line[read - 1] == '\n')
			read--;
		else
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//substr line and check
		map->grid[i] = ft_substr(line, 0, read);
		if (!(map->grid[i]))
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//register/check width
		if (i == 0)
			map->width = read;
		else
		{
			if (map->width != read)
			{
				free(line);
				free(map->grid);
				return (-1);
			}
		}
	}
	if (element_control(map->grid, elem->empty, elem->obstacle) == -1)
	{
		free(line);
		free_map(map->grid);
		return (-1);
	}
	free(line);
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

void	find_biggest_square(t_map* map, t_element* element, t_square* square)
{
	//declare a matrix
	int matrix[map->height][map->width];
	for (int i = 0; i < map->height; i++)
		for (int j = 0; j < map->width; j++)
			matrix[i][j] = 0;
	//bsq algo. check obstacle, border and min of surrounding
	for(int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j] == element->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int min = find_min(matrix[i - 1][j], matrix[i - 1][j -1], matrix[i][j - 1]);
				matrix[i][j] = min + 1;
			}
			//check if matrix of current bigger than square->size
			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - matrix[i][j] + 1;
				square->j = j - matrix[i][j] + 1;
			}
		}
	}	
}

void	print_square(t_map* map, t_square* square, t_element* elem)
{
	for (int i = square->i; i < square->i + square->size; i++)
		for (int j = square->j; j < square->j + square->size; j++)
			if (j < map->width && i < map->height)
				map->grid[i][j] = elem->full;
	for (int i = 0; i < map->height; i++)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}
}

int	execute_bsq(FILE* file)
{
	t_element element;
	if (loadElements(file, &element) == -1)
		return (-1);
	t_map	map;
	if (loadMap(file, &element, &map) == -1)
		return (-1);
	t_square square;
	square.i = 0, square.j = 0, square.size = 0;
	find_biggest_square(&map, &element, &square);
	print_square(&map, &square, &element);
	free_map(map.grid);
	return (0);
}

int	convert_fileptr(char *filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
		return (-1);
	int ret = execute_bsq(file);
	fclose(file);
	return (ret);
}
