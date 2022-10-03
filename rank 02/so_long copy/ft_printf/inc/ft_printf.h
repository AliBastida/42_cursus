/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:16:39 by abastida          #+#    #+#             */
/*   Updated: 2022/06/30 12:19:48 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_format(va_list arg, const char type);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
size_t	ft_len(long n);
int		ft_putnbr(long long num, int signo);
int		ft_printnbr(long long n);
int		ft_puthexa_low(unsigned long num);
int		ft_puthexa_upper(unsigned long num);
int		ft_ptrhexa(unsigned long pointer);

#endif
