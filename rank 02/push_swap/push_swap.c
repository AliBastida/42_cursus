/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:28:56 by abastida          #+#    #+#             */
/*   Updated: 2023/02/01 14:28:56 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_master **stack_a)
{
	t_master *temp;
	
	temp = *stack_a;

	while(temp != NULL)
	{
		printf("Valor del nodo: %d\n", temp->value);
		temp = temp->next;
	}
	temp = ft_last_list(stack_a);
	printf("--------Prev--------\n");
	while(temp != NULL)
	{
		printf("Valor del nodo: %d\n", temp->value);
		temp = temp->prev;
	}
}
int	main(int ac, char **av)
{
	t_master *num;

	if(ac < 2)
		exit(0);
	checking_error(av, ac);
	num = create_list(av);
	print_list(&num);
	return(0);
}

