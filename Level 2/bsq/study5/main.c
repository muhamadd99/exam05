/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:30:32 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/06 21:36:20 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		if (execute_bsq(stdin) == -1)
			fprintf(stdout, "Error: input");
	}
	else 
	{
		for (int i = 1; av[i]; i++)
		{
			if (convert_fileptr(av[i]) == -1)
				fprintf(stdout, "Error: input");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return (0);
}