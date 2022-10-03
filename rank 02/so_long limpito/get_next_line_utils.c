/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:10:23 by abastida          #+#    #+#             */
/*   Updated: 2022/09/29 11:59:30 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!s)
		return(0);
	
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

void	ft_strjoin_fill_new_string(char *new, char *s1, char *s2)
{
	int	i;
	int	j;
	
	i = 0;
	while ((s1[i] != '\0') && (i >= 0))
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while ((s2[j]) && (j >= 0))
	{
		new[i + j] = s2[j];
			j++;
	}
	new[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1)
	{
		printf("S1 Todavia no existe en este momento\n");
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	ft_strjoin_fill_new_string(new, s1, s2);
	free(s1);
	return (new);
}
