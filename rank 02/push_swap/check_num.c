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
		if ((ft_isdigit(s[i]) == 1) || (s[0] == '-' && ft_isdigit(s[i + 1] == 1)))
			i++;
		else
			ft_error(1);
	}
}
