/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:11:17 by chmurphy          #+#    #+#             */
/*   Updated: 2023/06/27 17:18:13 by chmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	buffer[512][10960];
	char	*line;
	ssize_t	bytes_read;

	line = NULL;
	bytes_read = 0;
	if (fd == -1 || read(fd, &buffer[0][0], 0) == -1 || BUFFER_SIZE == 0)
		return (NULL);
	while (read(fd, &buffer[fd][bytes_read], 1) > 0 && \
											buffer[fd][bytes_read++] != '\n')
		;
	if (bytes_read == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (bytes_read + 1));
	if (!line)
		return (NULL);
	line[bytes_read] = '\0';
	while (--bytes_read > -1)
	{
		line[bytes_read] = buffer[fd][bytes_read];
	}
	return (line);
}
