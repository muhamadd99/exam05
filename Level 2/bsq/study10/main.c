/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:40:29 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/12/08 22:18:02 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int ac, char** av)
{
	if (ac == 1)
	{
		if (execute_bsq(stdin) == -1)
			fputs("Error: input", stdout);
	}
	else 
	{
		for(int i = 1; i < ac; i++)
		{
			if (convert_fileptr(av[i]) == -1)
				fputs("Error: input", stdout);
			if (i < ac - 1)
				fputs("\n", stdout);
		}
	}
	return 0;
}