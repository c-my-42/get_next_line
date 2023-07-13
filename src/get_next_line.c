/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:11:59 by chmurphy          #+#    #+#             */
/*   Updated: 2023/06/27 17:10:42 by chmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[10960];
	char	*line;
	ssize_t	bytes_read;

	bytes_read = 0;
	line = NULL;
	if (fd == -1 || read(fd, &buffer[0], 0) == -1 || BUFFER_SIZE == 0)
		return (NULL);
	while (read(fd, &buffer[bytes_read], 1) > 0 && buffer[bytes_read++] != '\n')
		;
	if (bytes_read == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (bytes_read + 1));
	if (!line)
		return (NULL);
	line[bytes_read] = '\0';
	while (--bytes_read > -1)
	{
		line[bytes_read] = buffer[bytes_read];
	}
	return (line);
}
