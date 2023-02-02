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

void	add_back(t_master **stack_a, t_master *temp)
{
	t_master *temp_node;

	temp_node = *stack_a;
	if(stack_a == NULL)
		*stack_a = temp;
	else
	{
		while(temp_node->next != NULL)
		{
			 temp_node = temp_node->next;				//tengo que comprobar que esta funcion esta bien porque me he hecho un lio con las vv temp_node y temp
		}
		temp_node->next = temp;
	}
}
