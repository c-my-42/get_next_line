################################	MAKEFILE	################################

NAME			= 	get_next_line

SIZE			= 	10

CC				= 	gcc -Wall -Wextra -Werror \
					-D BUFFER_SIZE=$(SIZE)

SRC				= 	$(wildcard *.c)
OBJS			= 	$(filter-out main, $(SRC:%.c=%.o))

AR				= 	ar rcsv

TESTS_DIR		= 	../tests/
FILE 			= 	$(TESTS_DIR)ten_up_down_nl.txt


RM				= rm -f

CLR_RMV 		= \033[0m
RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[1;34m
CYAN			= \033[1;36m

default: all

all: $(NAME).a

exe: $(NAME)
	./$< $(FILE)

$(NAME): $(NAME).a
	$(CC) -o $@ $< main.o

$(NAME).a: $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	@ $(RM) *.o */*.o
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@ $(RM) $(NAME) *.a
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean exe

.PHONY: all clean fclean re exe default
