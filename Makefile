################################	MAKEFILE	################################
DIR = tests/
TEST1 = $(DIR)10_up_down
TEST2 = $(DIR)variable_nls

default: | del
	make -C src re
	./get_next_line $(TEST1)

bonus: | del
	make -C bonus re
	./get_next_line_bonus $(TEST1) $(TEST2)

del:
	rm -f *.a

clean:
	make -C src clean
	make -C bonus clean

fclean:
	rm -f $(NAME) $(NAME)_bonus
	make -C src fclean
	make -C bonus fclean

.PHONY: clean fclean default bonus del
