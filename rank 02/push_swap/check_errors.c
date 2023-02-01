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
	if (n == 2)
	{
		exit(1);
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

void	check_if_ordered(char **av)
{
	int i;

	i = 1;
	while ((av[i]) && (ft_atoi(av[i-1]) < ft_atoi(av[i])))
		i++;
	if (av[i] == NULL)
		ft_error(2);
}

void	checking_error(char **argv, int argc)
{
	int i;

	i = 0;
	check_double(argv, argc);
	while (argv[++i])
	{
		check_num(argv[i]);
		check_num_max_min(argv);
		check_if_ordered(argv);
	}
}

