/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:34:53 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/24 18:13:08 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//check has parameter or not
//1 or 0?
int main(int ac, char **av)
{
	if (ac == 1)
	{
		if (execute_bsq(stdin) == -1)
			fprintf(stderr, "map error\n");
	}
	else 
	{
		for (int i = 1; i < ac; i++)
		{
			if (convert_file_pointer(av[i]) == -1)
				fprintf(stderr, "map error\n");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return (0);
}

