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
	ssize_t	i;

	i = 0;
	line = NULL;
	bytes_read = 1;
	if (fd == -1 || read(fd, &buffer[0][0], 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	while (read(fd, &buffer[fd][i], 1) > 0 && buffer[fd][i++] != '\n')
		bytes_read = 1;
	if (i == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i > -1)
	{
		line[i] = buffer[fd][i];
	}
	return (line);
}
