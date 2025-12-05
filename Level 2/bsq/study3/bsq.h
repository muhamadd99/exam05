/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:04:24 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/05 14:51:41 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_elements
{
	int		n_lines;
	char	empty;
	char	obstacle;
	char	full;
} t_elements;

typedef struct s_maps
{
	char**	grid;
	int		height;
	int		width;
} t_maps;

typedef struct s_square
{
	int	size;
	int	i;
	int	j;
} t_square;

int	execute_bsq(FILE* file);
int	convert_fileptr(char *filename);

#endif