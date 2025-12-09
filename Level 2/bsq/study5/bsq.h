/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:16:04 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/06 21:33:51 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	char**	grid;
	int		width;
	int		height;
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
	int		i;
	int		j;
	int		size;
} t_square;

int execute_bsq(FILE* file);
int convert_fileptr(char *filename);

#endif