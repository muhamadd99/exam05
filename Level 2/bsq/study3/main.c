/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:50:21 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/05 14:43:54 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//check no argument
//check with argument
int	main(int ac, char **av)
{
	if (ac == 1)
	{
		if(execute_bsq(stdin) == -1)
			fprintf(stderr, "Error: input error");
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			if (convert_fileptr(av[i]) == -1)
				fprintf(stderr, "Error: input error");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return (0);
}