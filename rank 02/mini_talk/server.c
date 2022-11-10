/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:27:39 by abastida          #+#    #+#             */
/*   Updated: 2022/11/10 12:37:31 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//#include "libftprintf.h"
#include <stdio.h>

int counting_bits;

void	handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char saved_bytes;

	counting_bits = 0;
	(void)info;
	(void)context;
   	if (signal == SIGUSR1)
		saved_bytes |= 1;
	counting_bits++;
	if (counting_bits == 8)
	{
		printf("%c\n", saved_bytes);
		counting_bits = 0;
	}
	saved_bytes <<= 1;
}

int	main(void)
{
	struct	sigaction signal;
	int		pid;
	
	pid = getpid();
	if(printf("PID:%d \n", pid) == -1)
		exit(0);
	signal.sa_sigaction = handler;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}

