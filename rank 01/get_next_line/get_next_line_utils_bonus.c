/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:10:23 by abastida          #+#    #+#             */
/*   Updated: 2022/09/16 12:23:10 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
 // Está corregido!!!
size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i] != '\0')
	i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == ((char) c))
		return ((char *)s);
	return (0);
}

char	*ft_strjoin_fill_new_string(char *new, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while ((s1[i] != '\0') && (i >= 0))
	{
		new [i] = s1[i];
		i++;
	}
	j = 0;
	while ((s2[j]) && (j >= 0))
	{
		new[i + j] = s2[j];
			j++;
	}
	new [i + j] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	new = ft_strjoin_fill_new_string(new, s1, s2);
	free(s1);
	return (new);
}
