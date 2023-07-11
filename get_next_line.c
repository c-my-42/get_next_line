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
	ssize_t	i;

	i = 0;
	line = NULL;
	bytes_read = 1;
	if (fd == -1 || read(fd, &buffer[0], 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	while (read(fd, &buffer[i], 1) > 0 && buffer[i++] != '\n')
	{
		bytes_read = 1;
	}
	if (i == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i > -1)
	{
		line[i] = buffer[i];
	}
	return (line);
}
