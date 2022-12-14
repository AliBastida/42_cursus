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

typedef struct s_struct
{
	int *sa;
}t_struct;
//check_errors.c//

void	ft_error(int n);
void	check_num(char *s);
void	check_double(char **argv, int argc);
void	checking_error(char **argv, int argc);

#endif
