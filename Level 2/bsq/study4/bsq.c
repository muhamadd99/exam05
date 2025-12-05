/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:31:46 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/05 18:46:54 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//check printable or not
//check invalid input
int	loadElements(FILE* file, t_elements* elem)
{
	int res = fscanf(file, "%d %c %c %c", &elem->n_lines, &elem->empty, 
		&elem->obstacle, &elem->full);
	
	if (res != 4)
		return (-1);

	if (elem->n_lines <= 0)
		return (-1);
	if (elem->empty == elem->full || elem->empty == elem->obstacle || elem->full == elem->obstacle)
		return (-1);
	if (elem->empty < 32 || elem->empty > 126)
		return (-1);
	if (elem->obstacle < 32 || elem->obstacle > 126)
		return (-1);
	if (elem->full < 32 || elem->full > 126)
		return (-1);
	return (0);
}

char*	ft_substr(char *arr, int start, int len)
{
	char*	str = (char *)malloc(len + 1);
	if (!str)
		return NULL;
	int		i = 0;
	int		j = 0;
	
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

//iterate map, free line by line
void	free_map(char** arr)
{
	int i = 0;

	if (!arr)
		return ;
	while(arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

int		element_control(char **map, char c1, char c2)
{
	for(int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
		{
			if (map[i][j] != c1 && map[i][j] != c2)
				return (-1);
		}
	}
	return (0);
}

//take heigh, declare map, and null terminate
//skip first newline
//get the first line
//minus one byte for newline, substr the first line
//register/check the map with read
int	loadMap(FILE* file, t_maps *maps, t_elements* elements)
{
	maps->height = elements->n_lines;
	maps->grid  = (char**)malloc((maps->height + 1) * sizeof(char *));
	maps->grid[maps->height] = NULL;

	char*	line = NULL;
	size_t	len = 0;

	if (getline(&line, &len, file) == -1)
	{
		free_map(maps->grid);
		return (-1);
	}
	for (int i = 0; i < maps->height; i++)
	{
		int read = getline(&line, &len, file);
		if (read == -1)
		{
			free(line);
			free_map(maps->grid);
			return -1;
		}
		if (line[read - 1] == '\n')
			read--;
		else
		{
			free(line);
			free_map(maps->grid);
			return (-1);
		}
		maps->grid[i] = ft_substr(line, 0, read);
		if (!(maps->grid[i]))
		{
			free(line);
			free_map(maps->grid);
			return (-1);
		}
		if (i == 0)
			maps->width = read;
		else
		{
			if (maps->width != read)
			{
				free(line);
				free_map(maps->grid);
				return (-1);
			}
		}
	}

	if (element_control(maps->grid, elements->empty, elements->obstacle) == -1)
	{
		free(line);
		free_map(maps->grid);
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

//matrix_init
//loop
//check obstacle mark as zero
//check obstacle mark as one
//find min between all 4
//if matrix bigger than square, register
void	find_big_square(t_maps *map, t_square* square, t_elements* element)
{
	int	matrix[map->height][map->width];
	for (int i = 0; i < map->height; i++)
		for(int j = 0; j < map->width; j++)
			matrix[i][j] = 0;

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
				int min = find_min(matrix[i][j - 1], matrix[i - 1][j - 1], matrix[i - 1][j]);
				matrix[i][j] = min + 1;
			}

			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - square->size + 1;
				square->j = j - square->size + 1;
			}
		}
	}
}

//alter the square area
//print all
void	print_filled_square(t_maps* map, t_square* square, t_elements* element)
{
	for (int i = square->i; i < square->i + square->size; i++)
	{
		for (int j = square->j; j < square->j + square->size; j++)
		{
			if (j < map->width && i < map->height)
				map->grid[i][j] = element->full;
		}
	}

	int i = 0;
	while(map->grid[i])
	{
		fputs( map->grid[i], stdout);
		fputc('\n', stdout);
		i++;
	}
}

int execute_bsq(FILE* file)
{
	//load elements
	t_elements	elements;
	if (loadElements(file, &elements) == -1)
		return (-1);
	//load maps
	t_maps	maps;
	if (loadMap(file, &maps, &elements) == -1)
		return (-1);
	t_square square;
	square.i = 0; square.j = 0; square.size = 0;
	find_big_square(&maps, &square, &elements);
	print_filled_square(&maps, &square, &elements); //why need all
	free_map(maps.grid);
	return 0;
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