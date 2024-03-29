/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:01:07 by abastida          #+#    #+#             */
/*   Updated: 2023/02/12 10:59:11 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_master
{
	int value;
	int index;
	int length_list;
	struct s_master *next;
	struct s_master *prev;
}t_master;

typedef struct s_stack
{
	t_master *a;
	t_master *b;
}t_stack;

//push_swap.c//
int main(int ac, char **av);

//list_utils.c//
t_master *new_node(char **av);
void	add_back(t_master **stack_a, t_master *new);
t_master *ft_last_list(t_master **stack_a);

//init.c//
t_master	*create_list(t_stack *a, char **av);

//check_errors.c//

void	ft_error(int n);
void	check_if_ordered(char **av);
void	check_double(char **argv, int argc);
void	checking_error(char **argv, int argc);

//check_num.c//

void	check_num(char *s);
void	check_num_max_min(char **av);


#endif
