/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:27:39 by abastida          #+#    #+#             */
/*   Updated: 2022/11/15 14:19:45 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int counting_bits;

void	handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char saved_bytes;

	(void)context;
	usleep(100);
	if (counting_bits == 0)
		saved_bytes = 0;
   	if (signal == SIGUSR1)
	{
		saved_bytes |= 1;
		if (kill(info->si_pid, SIGUSR1) == -1)
			if (write(1, "The signal is not send\n", 26)  == -1)
				exit(-1);
	}
	if(signal == SIGUSR2)
	{
		if (kill(info->si_pid, SIGUSR1) == -1)
			if (write(1, "The signal is not send\n", 26) == -1)
				exit (-1);
	}
	counting_bits++;
	if (counting_bits == 8)
	{
		if(write(1, &saved_bytes, 1) == -1)
			exit(-1);
		if(saved_bytes == '\0')
			if(kill(info->si_pid, SIGUSR2) == -1)
				exit(-1);
		counting_bits = 0;
	}
	saved_bytes <<= 1;
}

int	main(void)
{
	struct	sigaction signal;
	int		pid;
	
	counting_bits = 0;
	pid = getpid();
	if(ft_printf("PID:%d \n", pid) == -1)
		exit(-1);
	signal.sa_sigaction = handler;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}

