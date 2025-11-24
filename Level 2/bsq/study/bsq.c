/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:31:51 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/24 18:17:29 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	loadElements(FILE* file, t_elements *element)
{
	int ret = fscanf(file, "%d %c %c %c", &element->n_lines,
		&element->empty, &element->obstacle, &element->full);
	if (ret != 4)
		return -1;
	if (element->n_lines <= 0)
		return -1;
	if (element->empty == element->obstacle && element->empty == element->full
			&& element->obstacle == element->full)
		return -1;
	if (element->empty < 32 || element->empty > 126)
		return -1;
	if (element->obstacle < 32 || element->obstacle > 126)
		return -1;
	if (element->full < 32 || element->full > 126)
		return -1;
	return 0;
}

void	free_map(char** arr)
{
	int i = 0;
	if(arr)
	{
		while(arr[i] != NULL)
		{
			if(arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	element_control(char** map, char c1, char c2)
{
	for (int i = 0; map[i]; i++)
		for (int j = 0; map[i][j]; j++)
			if (map[i][j] != c1 && map[i][j] != c2)
				return (-1);
	return (0);
}

char* ft_substr(char *arr, int start, int len)
{
	char* str = (char *)malloc(len + 1);
	if (!str)
		return NULL;
	int i = 0;
	int j = 0;
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

int	loadMaps(FILE* file, t_maps *map, t_elements *element)
{
	map->height = element->n_lines;
	map->grid = (char**)malloc((map->height + 1) * (sizeof(char *)));
	map->grid[map->height] = NULL;
	char* line = NULL;
	size_t len = 0;
	
	if(getline(&line, &len, file) == -1)
	{
		free_map(map->grid);
		return (-1);
	}
	for(int i = 0; i < map->height; i++)
	{
		//getline and the bytes
		int read = getline(&line, &len, file);
		if (read == -1)
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//check newline and uncount from read
		if (line[read - 1] == '\n')
			read--;
		else
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}
		//substr, store map
		map->grid[i] = ft_substr(line, 0, read);
		if (!(map->grid[i]))
		{
			free(line);
			free_map(map->grid);
			return(-1);
		}
		//register width & check width same or not
		if(i == 0)
			map->width = read;
		else
		{
			if (read != map->width)
			{
				free(line);
				free_map(map->grid);
				return (-1);
			}
		}
		//check line content
		if(element_control(map->grid, element->empty, element->obstacle) == -1)
		{
			free(line);
			free_map(map->grid);
			return(-1);
		}
	}
	free(line);
	return (0);
}

int find_min(int n1, int n2, int n3)
{
	int min = n1;

	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return min;
}

void	findBigSquare(t_maps* map, t_square* square, t_elements* element)
{
	//iterate row by row
	int matrix[map->height][map->width];
	for (int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
			matrix[i][j] = 0;
	}
	//start algo
	for(int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j] == element->obstacle)
				matrix[i][j] = 0;			
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
				matrix[i][j] = min + 1;
			}
			//register size of square, position x y
			if(matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->x = j - matrix[i][j] + 1;
				square->y = i - matrix[i][j] + 1;
			}
		}
	}
}

void	printFilledSquare(t_maps* map, t_square *square, t_elements* element)
{
	//replace
	for (int i = square->y; i < square->y + square->size; i++)
		for (int j = square->x; j < square->x + square->size; j++)
			if((i < map->height) && (j < map->width))
				map->grid[i][j] = element->full;
	//print out dari awal
	for(int i = 0; i < map->height; i++)
	{
		fputs(map->grid[i], stdout);
		fputc('\n', stdout);
	}
	
}

int	execute_bsq(FILE* file)
{
	t_elements element;
	t_maps map;
	t_square square;

	if (loadElements(file, &element) == -1)
		return (-1);
	if (loadMaps(file, &map, &element) == -1)
		return (-1);
	square.size = 0; square.x = 0; square.y = 0;
	findBigSquare(&map, &square, &element); //why no return?
	printFilledSquare(&map, &square, &element);
	free_map(map.grid);
	return (0);
}

int	convert_file_pointer(char *fileName)
{
	FILE* file = fopen(fileName, "r");
	if (!file)
		return (-1);
	int ret = execute_bsq(file);
	fclose(file);
	return (ret);
}

