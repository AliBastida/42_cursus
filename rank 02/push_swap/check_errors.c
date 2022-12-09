/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:00:28 by abastida          #+#    #+#             */
/*   Updated: 2022/12/09 14:21:10 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int n)
{
	if (n == 1)
	{
		write (2, "Error param number\n", 18);
		exit (1);
	}
	if (n == 2)
	{
		write (2, "Not only numbers\n", 15);
		exit(1);
	}
	if (n == 3)
	{
		write (2, "There are numbers duplicate\n", 27);
		exit (1);
	}
}

void	is_num(char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if ((argv[0] == '-') || (argv[0] == '+') 
			|| ((argv[i] < '0') && (argv[i] > '9')))
				ft_error(2);
	}
}

void	check_double(char **argv, int i)
{
	int j;

	j = i + 1;
	while (argv[j])// strncmp
		if (argv[i] == argv[j])
			ft_error(3);
		j++;
}

void	checking_error(char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		is_num(argv[i]);
		check_double(argv, i);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error(1);
	checking_error(argv);
	return(0);
}

//se me queda atascado en un while!!!
