/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:00:49 by abastida          #+#    #+#             */
/*   Updated: 2022/10/17 19:01:01 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"
#include <stdarg.h>

int	ft_format(va_list arg, const char type)
{
	int	len;

	len = 0;
	if ((type == 'c') || (type == '%'))
		len += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if ((type == 'd') || (type == 'i'))
		len += ft_putnbr(va_arg(arg, int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start (arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
