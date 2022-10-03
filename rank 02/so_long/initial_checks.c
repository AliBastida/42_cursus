/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:11:52 by abastida          #+#    #+#             */
/*   Updated: 2022/09/13 16:05:06 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"



int check_num_params_are_valid(int argc)
{
	if(argc != 2)
	{
		write(2, "Error: num params are invalid\n", 30);
		return(0);
	}
	return(1);
}

int	check_filename_is_valid(char *filename)
{
	int length;
	int error;

	error = 0;
	length = ft_strlen(filename); 
	//si no  ocupa almenos 5 caracteres (x.ber)
	if(length < 5)
		error = 1; 
	else
	{
		//Termina en .ber
		if (filename[length -1] != 'r')
			error = 1;
		else if (filename[length -2] != 'e')
			error = 1;
		else if (filename[length -3] != 'b')
			error = 1;
		else if (filename[length -4] != '.')
			error = 1;
	}
	if(error == 1)
	{
		write(2, "Error Invalid Filename\n", 24);
		return(0);
	}
	return(1);
}




//return 1 , if params are valids
//return 0, if params are invalids
int check_params_are_valids(int argc, char **argv)
{
	if(!check_num_params_are_valid(argc))
		return(0);
	if(!check_filename_is_valid(argv[1]))
		return(0);

	return(1);
}
