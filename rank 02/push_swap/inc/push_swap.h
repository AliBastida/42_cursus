/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:01:07 by abastida          #+#    #+#             */
/*   Updated: 2022/12/09 14:05:12 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//check_errors.c//

void	ft_error(int n);
void	is_num(char *argv);
void	check_double(char **argv, int i);
void	checking_error(char **argv);

#endif
