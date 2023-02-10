/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:27:17 by abastida          #+#    #+#             */
/*   Updated: 2023/02/10 16:01:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//en esta funcion creo los nodos y los voy enlazando al final.

void put_index(t_master node, t_master **stack_a)
{
	(void)node;
	int counter_index;
	t_master *temp_node;

	counter_index = 1;
	temp_node = *stack_a;
	while(temp_node != NULL)
	{
		temp_node = temp_node->next;
		counter_index++;
	}


}

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
	stack_a->length_list = i - 1;
	printf("length_list is: %d\n", stack_a->length_list);
	//crear una funcion que ponga los indices de cada nodo.
	return(stack_a);
}
