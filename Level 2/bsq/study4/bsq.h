/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:09:32 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/05 17:31:13 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_maps
{
	int 	width;
	int		height;
	char**	grid;
} t_maps;

typedef struct t_elements
{
	int		n_lines;
	char	empty;
	char	obstacle;
	char	full;
} t_elements;

typedef struct t_square
{
	int	i;
	int	j;
	int	size;
} t_square;

int	execute_bsq(FILE* file);
int	convert_fileptr(char* filename);

#endif