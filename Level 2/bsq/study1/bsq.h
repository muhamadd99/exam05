/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:54:02 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/24 22:17:38 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>

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
	int		size;
	int		x;
	int		y;
} t_square;

//function
int	bsq_execute(FILE* file);
//function
int convert_file(char* filename);

#endif