/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:53:07 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/08 10:54:34 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_map
{
	int		width;
	int		height;
	char**	grid;
} t_map;

typedef struct s_element
{
	int		nlines;
	char	empty;
	char	obstacle;
	char	full;
} t_element;

typedef struct s_square
{
	int	size;
	int	x;
	int	y;
} t_square;

int		execute_bsq(FILE* file);
int		convert_fileptr(char *filename);

#endif