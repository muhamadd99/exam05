/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:15:09 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/24 14:28:09 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_elements
{
	int		n_lines;
	char	empty;
	char	obstacle;
	char	full;
} t_elements;

//map
typedef struct s_maps
{
	char	**grid;
	int		width;
	int		height;
} t_maps;

//square
typedef struct s_square
{
	int size;
	int	x;
	int	y;
} t_square;

int	execute_bsq(FILE* filePtr);
int	convert_file_pointer(char *fileName);

#endif