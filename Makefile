################################	MAKEFILE	################################
NAME	= get_next_line

SIZE	= 5
MAIN	= main
CC		= gcc -Wall -Wextra -Werror \
		  -g \
			-D BUFFER_SIZE=$(SIZE) \
			-fsanitize=address

SRC			= get_next_line.c get_next_line_utils.c main.c
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
