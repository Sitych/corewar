NAME =
CFLAGS := -Wall -Wextra -Werror

DIR_ASM = asm/
DIR_VM = vm/

all:
	make -sC $(DIR_ASM)
	make -sC $(DIR_VM)
	@echo "DONE!"

clean:
	make -sC $(DIR_ASM) clean
	make -sC $(DIR_VM) clean

fclean: clean
	make -sC $(DIR_ASM) fclean
	make -sC $(DIR_VM) fclean

re: fclean all

.PHONY: all clean fclean re lib
