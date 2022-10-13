# include "so_long_bonus.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
		}
	return (1);
}

size_t	ft_len(long n)
{
	size_t i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
	}
char	*ft_itoa(int n)
{
	char *num;
	int contador;
	long a;

	a = (long)n;
	contador = ft_len(a);
	num = (char *) malloc(sizeof(char) * (contador + 1));
	if (!num)
		return (NULL);
	num[contador] = '\0';
	if (a == 0)
		num [0] = '0';
	else if (a < 0)
	{
		a *= -1;
		num [0] = '-';
	}
	while (a > 0)
	{
		num[--contador] = (a % 10) + '0';
		a /= 10;
	}
	return (num);
}

int ft_putnbr(int n)
{
	int len;
	char *num;
	(void)n;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}
