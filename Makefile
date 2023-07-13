################################	MAKEFILE	################################

default: | del
	make -C src re

bonus: | del
	make -C bonus re

del:
	rm -f *.a

clean:
	make -C src clean
	make -C bonus clean

fclean:
	make -C src fclean
	make -C bonus fclean

.PHONY: clean fclean default bonus del
