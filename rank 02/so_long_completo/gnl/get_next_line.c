/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:40:21 by abastida          #+#    #+#             */
/*   Updated: 2022/10/14 11:53:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include <unistd.h>

char	*filling_static_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_readed;

	buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	bytes_readed = 1;
	while (bytes_readed > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed > 0)
		{
			buffer[bytes_readed] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (bytes_readed == -1)
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	line = (char *)malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (i < 1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*save_storage(char *storage)
{
	int		i;
	int		j;
	char	*storage_saved;

	i = 0;
	j = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	storage_saved = (char *)malloc (sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!storage_saved)
		return (NULL);
	i++;
	while (storage[i])
		storage_saved[j++] = storage[i++];
	storage_saved[j] = '\0';
	free(storage);
	return (storage_saved);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = filling_static_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		free(storage);
		return (NULL);
	}
	storage = save_storage(storage);
	return (line);
}
