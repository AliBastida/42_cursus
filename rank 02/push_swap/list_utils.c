/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:31:07 by abastida          #+#    #+#             */
/*   Updated: 2023/02/02 12:30:06 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_master *ft_last_list(t_master **stack_a)
{
	t_master *last;
	last = *stack_a;
	while(last->next != NULL)
	{
		last = last->next;
	}
	return(last);
}
t_master *new_node(char **av)
{
	t_master *num;
	int i; 

	i = 0;
	num = (t_master *)malloc(sizeof(t_master));
	if(!num)
		return(NULL);
	num->value = ft_atoi(av[i]);
	num->next = NULL;
	num->prev = NULL;
	return(num);
}

void	add_back(t_master **stack_a, t_master *new)
{
	t_master *temp_node; // lo usamos solo como iterador

	temp_node = *stack_a;
	if(*stack_a == NULL)
		*stack_a = new;
	else
	{
		temp_node = ft_last_list(stack_a);
		temp_node->next = new;
		new->prev = temp_node;
	}
}

