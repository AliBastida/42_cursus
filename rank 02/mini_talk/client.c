/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:26:23 by abastida          #+#    #+#             */
/*   Updated: 2022/11/15 12:17:18 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

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
				exit(0);
		}
		usleep(300);
		byte <<= 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			sending_byte(atoi(argv[1]), argv[2][i]);
			i++;
		}
		sending_byte(atoi(argv[1]), '\0');
	}
	else
		if (write(1, "Invalid number of arguments\n", 28) == -1)
			exit(0);
	return (0);
}
