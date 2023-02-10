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

//esta funcion me sirve para printear la lista que voy creando, el nodo anterior y el siguiente.
//Gracias Sebas!!

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
	t_master *stack_a = NULL;
//	t_master *stack_b = NULL;

	if(ac < 2)
		exit(0);
	else
		checking_error(av, ac);
		stack_a = create_list(av);
		print_list(&stack_a);
	return(0);
}

