/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:37:50 by abastida          #+#    #+#             */
/*   Updated: 2022/09/16 12:21:04 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*filling_static_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_readed;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
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
	line = malloc (sizeof(char) * (i + 2));
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
	storage_saved = malloc (sizeof(char) * (ft_strlen(storage) - i + 1));
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
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = filling_static_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		return (NULL);
	}
	storage[fd] = save_storage(storage[fd]);
	return (line);
}
