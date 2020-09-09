NAME = asm
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADERS_DIR = $(LIBFT_DIR)includes/
LIB_FLAG := -L./$(LIBFT_DIR) -lft

HEADERS_DIR = includes/
HEADERS_LST = asm.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LST))
INCLUDES := -I $(HEADERS_DIR) -I $(LIBFT_HEADERS_DIR)

SRC_DIR = srcs/
SRC_DIR_PARSE = parse/
SRC_DIR_LOGIC = logic/
SRC_DIR_OUTPUT = output/

SRC_MAIN = main.c
SRC_PARSE_FILES =
SRC_LOGIC_FILES =
SRC_OUTPUT_FILES =

SRC_PARSE = $(addprefix $(SRC_DIR_PARSE), $(SRC_PARSE_FILES))
SRC_VALIDATE = $(addprefix $(SRC_DIR_VALIDATE), $(SRC_VALIDATE_FILES))
SRC_LOGIC = $(addprefix $(SRC_DIR_LOGIC), $(SRC_LOGIC_FILES))
SRC_OUTPUT = $(addprefix $(SRC_DIR_OUTPUT), $(SRC_OUTPUT_FILES))

SRCS_LST = $(SRC_MAIN) $(SRC_PARSE) $(SRC_VALIDATE) $(SRC_LOGIC) $(SRC_OUTPUT)
SRCS = $(addprefix $(SRC_DIR), $(SRCS_LST))

OBJ_DIR = objects/
OBJ_DIRS = $(addprefix $(OBJ_DIR), $(SRC_DIR_PARSE)) $(addprefix $(OBJ_DIR), $(SRC_DIR_LOGIC)) \
			$(addprefix $(OBJ_DIR), $(SRC_DIR_OUTPUT)) $(addprefix $(OBJ_DIR), $(SRC_DIR_VALIDATE))
OBJ_LST = $(patsubst %.c, %.o, $(SRCS_LST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LST))

all: lib $(NAME)

lib:
	make -sC $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(INCLUDES) $(LIB_FLAG) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIRS)

objects/%.o : srcs/%.c $(HEADERS)
	gcc $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re lib
