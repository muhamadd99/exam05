/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:14:45 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/25 14:40:58 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int loadElements(FILE* file, t_elements* element)
{
	int ret = fscanf(file, "%d %c %c %c", &element->n_lines, 
		&element->empty, &element->obstacle, &element->full);
	if (ret != 4)
		return -1;
	if (element->n_lines <= 0)
		return -1;
	if(element->n_lines == element->empty && element->n_lines == element->obstacle)
		return -1;
	if (element->empty == element->obstacle)
		return -1;
	if (element->empty < 32 || element->empty > 126)
		return -1;
	if (element->obstacle < 32 || element->obstacle > 126)
		return -1;
	if (element->full < 32 || element->full > 126)
		return -1;
}


int loadMaps(FILE* file, t_elements* element, t_maps* map)
{
	
}

//load element
//load map
//find biggest square, print map, free
int	bsq_execute(FILE* file)
{
	t_elements	element;
	t_maps		map;
	t_square	square;

	if (loadElements(file, &element) == -1)
		return (-1);
	if (loadMaps(file, &element, &map) == -1)
		return (-1);
	square.size = 0; square.x = 0; square.y = 0;
	find_biggest_square(&element, &map, &square);
	print_filled_maps(&element, &map, &square);
	return (0);
}

//filename to file pointer
//call bsq_execute
//return ret
int	convert_file(char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
		return -1;
	int ret = bsq_execute(file);
	fclose(file);
	return (0);
}	