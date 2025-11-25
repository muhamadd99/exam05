/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:03:30 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/25 14:44:11 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdio.h>
#include <stdlib.h>
//#include <>

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
	int	x;
	int	y;
} t_square;

int	execute_bsq(FILE* file);
int	convert_fileptr(char *filename);

#endif