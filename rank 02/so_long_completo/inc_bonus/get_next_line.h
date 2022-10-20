/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:42:50 by abastida          #+#    #+#             */
/*   Updated: 2022/10/20 14:37:49 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(char *str);

#endif
