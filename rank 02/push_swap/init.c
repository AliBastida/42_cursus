/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:27:17 by abastida          #+#    #+#             */
/*   Updated: 2023/02/01 19:21:30 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_master *create_list(char **av)
{
	int i;
	t_master *temp;
	t_master *stack_a;

	i = 2;
	stack_a = new_node(&av[1]);
	while(av[i])
	{
		temp = new_node(&av[i]);
			if(!temp)
				exit(1);
		add_back(&stack_a, temp);
		i++;
	}
	//crear una funcion que ponga los indices de cada nodo.
	return(&stack_a);
}
