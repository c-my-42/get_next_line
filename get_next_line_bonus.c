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
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[4096][10960];
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
		line[i] = buffer[fd][i];
	return (line);
}
/*#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	ssize_t fd;
	ssize_t	fd_2;
	char	*arr;
	char	*str;

	if (argc < 2)
	{
		printf("Please enter file name:\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	fd_2 = open(argv[2], O_RDONLY);
	while ((arr = get_next_line(fd)))//))
	{
		if ((str = get_next_line(fd_2)))
			printf("%s", str);
		printf("%s", arr);
	}
	while ((str = get_next_line(fd_2)))
		printf("%s", str);
	close(fd_2);
	close(fd);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

										MAKEFILE
NAME	= get_next_line

SIZE	= 5
MAIN	= main
CC		= gcc -Wall -Wextra -Werror \
		  -g \
			-D BUFFER_SIZE=$(SIZE) \
#			-fsanitize=address

SRCS			= get_next_line.c get_next_line_utils.c main.c
#$(filter-out bonus, $(wildcard *.c) $(wildcard *//*.c))
#BONUS			= $(wildcard *bonus.c) $(wildcard **bonus.c) main.c
OBJS			= $(filter-out main, $(SRCS:.c=.o))
#BONUS_OBJS		= $(filter-out main, $(BONUS:.c=.o))
AR				= ar rcsv
MAIN_O			= main.o
TESTS_DIR		= tests/
FILE 			= $(TESTS_DIR)varying_line_lengths.txt\
#$(TESTS_DIR)lines_around_10.txt
RM				= rm -f


CLR_RMV 		= \033[0m
RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[1;34m
CYAN			= \033[1;36m

default: all

#bonus:  exe_bonus

#exe_bonus: $(NAME)_bonus
#	/$< $(FILE)

#$(NAME)_bonus: $(NAME)_bonus.a clean
#	$(CC) -o $@ $(MAIN_O) $<

#$(NAME)_bonus.a: $(BONUS_OBJS)
#	$(AR) $@ $^

all: $(NAME).a

exe: $(NAME)
	./$< $(FILE)

debug: clean
	lldb ./$(NAME)
	run $(FILE)

$(NAME): $(NAME).a
	$(CC) -o $@ $< $(MAIN_O)

$(NAME).a: $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	@ $(RM) *.o *//*.o
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@ $(RM) $(NAME) *.a
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re bonus debug exe default bonus exe_bonus
*/
