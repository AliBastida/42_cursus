/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:07:49 by abastida          #+#    #+#             */
/*   Updated: 2023/01/09 13:59:50 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	check_num(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (ft_isdigit(s[i]) || (s[0] == '-' && ft_isdigit(s[i + 1])))
			i++;
		else
			ft_error(1);
	}
}

void	check_num_max_min(char **av)
{
	int i;
	int j;
	int len;

	i = 1;
	while(av[i])
	{
		j = 0;
		len = ft_strlen(av[i]);
		while(av[i][j])
		{
			if(len > 11)
				ft_error(1);
			else if ((len == 11 && ft_strncmp(av[i], "-2147483648", 11) > 0)
				|| (len == 10 && ft_strncmp(av[i], "2147483647", 10) > 0))
				ft_error(1);
			j++;
		}	
		i++;
	}
}

