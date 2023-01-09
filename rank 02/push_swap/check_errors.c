/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:00:28 by abastida          #+#    #+#             */
/*   Updated: 2023/01/09 14:02:25 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int n)
{
	if (n == 1)
	{
		write (2, "Error\n", 5);
		exit (1);
	}
}

void	check_double(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	j = i + 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (argv[j])
		{
			if(ft_strncmp(argv[i], argv[j], 11) == 0)
				ft_error(1);
			else
				j++;
		}
		i++;
	}
}

void	checking_error(char **argv, int argc)
{
	int i;

	i = 0;
	check_double(argv, argc);
	while (argv[++i])
		check_num(argv[i]);
}

int	main(int argc, char **argv)
{
	t_struct *list;

	list = malloc(sizeof(t_struct));
	if (!list)
		return(0);
	if (argc < 2)
		exit (0);
	checking_error(argv, argc);
	return(0);
}

//de errores tengo que comprobar si es el int max o el int min.
//tb tengo que comprobar si los numeros estan ordenados ya.

