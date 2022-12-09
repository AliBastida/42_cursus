/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:26:23 by abastida          #+#    #+#             */
/*   Updated: 2022/12/07 13:40:11 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	reciving_bytes(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
	{
		write(1, "The signal is recieved\n", 24);
<<<<<<< HEAD
		exit(EXIT_FAILURE);
=======
		exit(0);
>>>>>>> 3ebfd169cb7b5b7aab13436aad92da260f7401c2
	}
}

void	sending_byte(int pid, char byte)
{
	int		i;
	int		signal;
	int		kill_failure;

	i = 0;
	while (i < 8)
	{
		if (byte & 128)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		kill_failure = kill(pid, signal);
		if (kill_failure < 0)
		{
			if (write(1, "Signal error\n", 14) == -1)
				exit(EXIT_FAILURE);
		}
		usleep(300);
		usleep(100);
		byte <<= 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	signal(SIGUSR1, reciving_bytes);
	signal(SIGUSR2, reciving_bytes);
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) < 1)
			exit (0);
		while (argv[2][i])
		{
			sending_byte(atoi(argv[1]), argv[2][i]);
			i++;
		}
		sending_byte(atoi(argv[1]), '\0');
	}
	else
		if (write(1, "Invalid number of arguments\n", 29) == -1)
			exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
