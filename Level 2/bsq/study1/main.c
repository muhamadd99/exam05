/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:59:37 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/24 22:16:38 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

//check no arg/filename
int main(int ac, char **av)
{
	if(ac == 1)
	{
		if (bsq_execute(stdin) == -1)
			fprintf(stderr, "Error: map error");
	}
	else 
	{
		for(int i = 0; i < ac ;i++)
		{
			if (convert_file(av[i]) == -1)
				fprintf(stderr, "Error: map error");
			if (i < ac - 1)
				fprintf(stdout, "\n");
		}
	}
	return (0);
}