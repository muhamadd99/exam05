/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:42:49 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/08 09:09:14 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stddef.h>

int	loadElements(FILE* file, t_element* e)
{
	int res = fscanf(file, "%d %c %c %c", &e->nlines, &e->empty, &e->obstacle, &e->full);
	if (res != 4)
		return (-1);
	if (e->nlines <= 0)
		return (-1);
	if (e->empty == e->full || e->empty == e->obstacle || e->full == e->obstacle)
		return (-1);
	if (e->empty < 32 || e->empty > 126)
		return (-1);
	if (e->full < 32 || e->full > 126)
		return (-1);
	if (e->obstacle < 32 || e->obstacle > 126)
		return (-1);
	return (0);
}

char*	ft_substr(char* arr, int start, int len)
{
	int		i = 0;
	int		j = 0;
	char*	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	
	while (arr[i])
	{
		if (i >= start && j < len)
		{
			str[j] = arr[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char*	free_map(char **map)
{
	if (map)
	{
		for (int i = 0; map[i]; i++)
			free(map[i]);
		free(map);
	}
}

int	element_control(char **map, char c1, char c2)
{
	for (int i = 0; map[i]; i++)
		for (int j = 0; map[i][j]; j++)
			if (map[i][j] != c1 && map[i][j] != c2)
				return (-1);
}

int	loadMap(FILE* file, t_element* elem, t_map* map)
{
	map->height = elem->nlines;
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (-1);
	map->grid[map->height] = NULL;
	char	*line = NULL;
	size_t	len = 0;
	
	//skip first \n
	if (getline(&line, &len, file) == -1)
	{
		free_map(map->grid);
		return (-1);
	}
	//iterate and see all
	for (int i = 0; i < map->height; i++)
	{
		int read = getline(&line, &len, file);
		if (read == -1)
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//check newline and decrement read for substr
		if (line[read - 1] == '\n')
			read--;
		else
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//substr
		map->grid[i] = ft_substr(line, 0, read);
		if (!(map->grid[i]))
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//check map width
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
	return (min);
}

void	find_square(t_map* map, t_square* square, t_element* element)
{
	//matrix init
	int matrix[map->height][map->width];
	
	for(int i = 0; i < map->height; i++)
		for(int j = 0; j < map->width; j++)
			matrix[i][j] = 0;
	
	//bsq algorithm
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j] == element->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j -1]);
				matrix[i][j] = min + 1;
			}
			//fill square value
			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - square->size + 1;
				square->j = j - square->size + 1;
			}
		}
	}
}

void	print_square(t_map* map, t_square* square, t_element* elements)
{
	for (int i = square->i; i < square->i + square->size; i++)
		for (int j = square->j; j < square->j + square->size; j++)
			if (i < map->height && j < map->width)
				map->grid[i][j] = elements->full;
	for (int i = 0; map->grid[i]; i++)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}
}

int	execute_bsq(FILE* file)
{
	t_element	element;
	if (loadElements(file, &element) == -1)
		return -1;
	t_map		map;
	if (loadMap(file, &element, &map) == -1)
		return -1;
	t_square	square;
	square.size = 0; square.i = 0; square.j = 0;
	find_square(&map, &square, &element);
	print_square(&map, &square, &element);
	free_map(map.grid);
	return (0);
}

int	convert_fileptr(char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
		return -1;
	int ret = execute_bsq(file);
	fclose(file);
	return ret;
}