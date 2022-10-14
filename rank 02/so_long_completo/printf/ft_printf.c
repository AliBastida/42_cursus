#include "../inc/libftprintf.h"

#include <stdarg.h>

int	ft_format(va_list arg, const char type)
{
	int len; 

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
	va_list arg;

	int	i;
	int	len;
	
	va_start (arg, str);
	i = 0;
	len = 0;
	 while (str[i])
	{
		if (str[i] == '%')
			{
				len += ft_format(arg, str[i + 1]);
				i+=2;
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

/*int main(void)
{
	printf ("Hola %c\n", 'A');
	ft_printf("Hola %c\n", 'A');

	printf ("Hola %c\n", '%');
	ft_printf("Hola %c\n", '%');
	
	printf ("hola %s\n", "caracola");
	ft_printf("hola %s\n", "cosa bonita");

	printf ("42 %d\n", 547);
	ft_printf("42 %d", 547);
	return (0);
}*/

