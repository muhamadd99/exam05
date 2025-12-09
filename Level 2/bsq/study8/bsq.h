/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:16:09 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/08 13:04:29 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_element
{
	int		nlines;
	char	empty;
	char	full;
	char	obstacle;
} t_element;

typedef struct s_map
{
	char**	grid;
	int		height;
	int		width;
} t_map;

typedef struct s_square
{
	int	size;
	int	i;
	int	j;
} t_square;

int execute_bsq(FILE* file);
int	convert_fileptr(char* filename);

#endif