################################	MAKEFILE	################################

NAME			= get_next_line_bonus

CC				= gcc -Wall -Wextra -Werror -o
AR				= ar rcsv

all: ../$(NAME)

../$(NAME): $(NAME).o main.o
	$(CC) $@ $^

$(NAME).o:
	$(CC) $@ -c $(NAME).c

main.o:
	$(CC) $@ -c main.c

RM				= rm -f

CLR_RMV 		= \033[0m
RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[1;34m
CYAN			= \033[1;36m

clean:
	@ $(RM) *.o */*.o
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@ $(RM) $(NAME) *.a
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re
