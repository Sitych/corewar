# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snorcros <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:42:32 by snorcros          #+#    #+#              #
#    Updated: 2020/07/25 12:34:03 by snorcros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS := -o2 -Wall -Wextra -Werror
INCLUDES := includes/

HEADERS_LST = colors.h  funfortypes.h libft.h libftprintf.h unixtime.h header_double.h
HEADERS = $(addprefix $(INCLUDES), $(HEADERS_LST))

# ft
FT_DIR = ft/
SRC_FT_LIST = ft_atoi.c		ft_bzero.c		ft_memccpy.c	ft_memchr.c		ft_lstmerge.c\
	  ft_memcmp.c	ft_memcpy.c		ft_memmove.c 	ft_memset.c		ft_lstremove_if.c\
	  ft_strlen.c	ft_strcmp.c		ft_isalnum.c	ft_lstqsort.c	ft_lstadd_back.c\
	  ft_strcpy.c	ft_strncpy.c	ft_strcat.c		ft_strncat.c	ft_lstfind.c\
	  ft_strlcat.c	ft_strchr.c		ft_strrchr.c	ft_strstr.c		ft_lstmap.c\
	  ft_strnstr.c	ft_strncmp.c	ft_isalpha.c	ft_isdigit.c	ft_putnbr_fd.c\
	  ft_isascii.c	ft_toupper.c	ft_tolower.c	ft_isprint.c	ft_strdup.c\
	  ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c		ft_lstswap.c\
	  ft_strclr.c	ft_striter.c	ft_striteri.c	ft_strmap.c		ft_strmapi.c \
	  ft_strequ.c	ft_strnequ.c	ft_strsub.c		ft_strjoin.c	ft_strtrim.c\
	  ft_putchar.c	ft_putendl.c	ft_putstr.c		ft_strsplit.c	ft_itoa.c\
	  ft_putnbr.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c get_next_line.c\
	  ft_lstnew.c	ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		ft_lstiter.c \
	  ft_qsort.c	ft_lstsize.c	ft_lstlast.c	ft_lsti.c		ft_lstreverse.c\
	  free_table.c  ft_itoabase.c   ft_itoahex.c    ft_itoa_signed.c ft_itoadouble.c\
	  ft_stradd_front.c ft_stradd_back.c    ft_strreplace.c ft_strcat_front.c ft_strcut.c\
	  new_table.c

SRC_FT = $(addprefix $(FT_DIR), $(SRC_FT_LIST))

# ft_printf
SRC_PRINTF_LIST =	fun_flags.c	fun_length.c length_bonus.c parse.c	placeholder.c	printf.c\
                    precision.c type_unixtime.c unixtime.c  type_color.c flag_hash.c\
                    funtypes_ubp.c funtypes_cdx_upx_o.c funtypes_sf_percent.c\
                    bonus_star.c get_flag_sign.c set_precision_width.c\
					ft_kek.c ft_double.c ft_longarith.c

PRINTF_DIR = ft_printf/
SRC_PRINTF = $(addprefix $(PRINTF_DIR), $(SRC_PRINTF_LIST))

# all srcs
SRC_DIR = srcs/
SRCS_LIST = $(SRC_FT) $(SRC_PRINTF)
SRCS = $(addprefix $(SRC_DIR), $(SRCS_LST))

OBJ_DIR = objects/
OBJ_DIRS = $(addprefix $(OBJ_DIR), $(FT_DIR)) $(addprefix $(OBJ_DIR), $(PRINTF_DIR))
OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIRS)

objects/%.o: srcs/%.c $(HEADERS)
	gcc $(CFLAGS) -c -I $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
