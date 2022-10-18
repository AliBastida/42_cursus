/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:28:01 by abastida          #+#    #+#             */
/*   Updated: 2022/10/18 11:28:23 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_format(va_list arg, const char type);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
size_t	ft_len(long n);
char	*ft_itoa(int n);
int		ft_putnbr(int n);

#endif