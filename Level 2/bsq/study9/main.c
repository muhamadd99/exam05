/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:14:45 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/08 15:20:40 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		if (execute_bsq(stdin) == -1)
			fprintf(stdout, "Error: input");
	}
	else 
	{
		for (int i = 1; i < ac; i++)
		{
			if (convert_fileptr(av[i]) == -1)
				fprintf(stdout, "Error: input");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return (0);
}