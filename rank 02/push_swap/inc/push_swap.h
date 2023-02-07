/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:01:07 by abastida          #+#    #+#             */
/*   Updated: 2023/01/09 13:59:53 by abastida         ###   ########.fr       */
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
	struct s_master *next;
	struct s_master *prev;
	struct s_master *stack_a;
	struct s_master *stack_b;
}t_master;

//push_swap.c//
int main(int ac, char **av);

//list_utils.c//

t_master *new_node(char **av);
void	add_back(t_master **stack_a, t_master *new);
t_master *ft_last_list(t_master **stack_a);

//init.c//
t_master	*create_list(char **av);
//check_errors.c//

void	ft_error(int n);
void	check_if_ordered(char **av);
void	check_double(char **argv, int argc);
void	checking_error(char **argv, int argc);

//check_num.c//

void	check_num(char *s);
void	check_num_max_min(char **av);


#endif
