/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:06:39 by fatkeski          #+#    #+#             */
/*   Updated: 2025/11/24 14:10:01 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		if(execute_bsq(stdin) == -1)
			fprintf(stderr, "Error: map error\n");
	}
	else
	{
		for(int i = 1; i < argc; i++)
        {
            if(convert_file_pointer(argv[i]) == -1)
                fprintf(stderr, "Error: map error\n");
            if(i < argc - 1)
                fprintf(stdout, "\n");
        }
	}
	return(0);
}
