/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:27:17 by abastida          #+#    #+#             */
/*   Updated: 2023/02/12 10:57:54 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_index(t_master *stack_a)
{
	t_master *compare;
	t_master *temp;
	int index;
	int counter;

	compare = stack_a;
	temp = stack_a;
	counter = 0;
	while(temp != NULL && compare != NULL)
	{
		index = 0;
		while(counter < stack_a->length_list)
		{
			if(temp->value > compare->value)
				index++;
			compare = compare->next;
		}
		temp->index = index;
		temp = temp->next;
		counter++;
	}
}

//en esta funcion creo los nodos y los voy enlazando al final.
t_master *create_list(t_stack *a, char **av)
{
	int i;
	t_master *temp;

	i = 2;
	a = new_node(&av[1]);
	while(av[i])
	{
		temp = new_node(&av[i]);
			if(!temp)
				exit(1);
		add_back(&a, temp);
		i++;
	}
	a->length_list = i - 1;
	printf("length_list is: %d\n", a->length_list);
	put_index(a);
	//crear una funcion que ponga los indices de cada nodo.
	return(a);
}
