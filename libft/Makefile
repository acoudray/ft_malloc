# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 14:37:39 by gmachena          #+#    #+#              #
#    Updated: 2020/02/21 16:31:11 by gmachena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_PATH = ./src/

SRC_NAME =			 ft_atoi.c \
					 ft_uimin.c \
					 ft_rgb_add.c \
					 fclamp.c \
					 ft_uiclamp.c \
					 ft_vectcpy.c \
					 ft_bzero.c \
					 ft_countcwords.c \
					 ft_isalnum.c \
					 ft_isalpha.c \
					 ft_isascii.c \
					 ft_isdigit.c \
					 ft_islower.c \
					 ft_iswp.c \
					 ft_isprint.c\
					 ft_itoa.c \
					 ft_isupper.c \
					 ft_memccpy.c \
					 ft_memdel.c \
					 ft_memchr.c \
					 ft_toupper.c \
					 ft_tolower.c \
					 ft_strtrim.c \
					 ft_strstr.c\
					 ft_strsub.c \
					 ft_strsplit.c \
					 ft_strrchr.c \
					 ft_strnstr.c \
					 ft_strnew.c\
					 ft_strnequ.c \
					 ft_strncpy.c \
					 ft_strncmp.c \
					 ft_strncat.c \
					 ft_strmapi.c\
					 ft_strmap.c \
					 ft_strlen.c \
					 ft_strlcat.c \
					 ft_strjoin.c \
					 ft_striteri.c \
					 ft_striter.c \
					 ft_strequ.c \
					 ft_strdup.c \
					 ft_strdel.c \
					 ft_strctrim.c\
					 ft_strcpy.c \
					 ft_strcmp.c \
					 ft_strclr.c \
					 ft_strclen.c \
					 ft_strchr.c \
					 ft_strcat.c \
					 ft_putstr_fd.c \
					 ft_putstr.c \
					 ft_putnbr_fd.c \
					 ft_putnbr.c\
					 ft_putendl_fd.c \
					 ft_putendl.c \
					 ft_putchar_fd.c \
					 ft_putchar.c \
					 ft_atof.c \
					 ft_memset.c \
					 ft_memmove.c \
					 ft_memcpy.c \
					 ft_memcmp.c \
					 ft_lstmap.c \
					 ft_lstnew.c \
					 ft_lstiter.c \
					 ft_lstdelone.c \
					 ft_lstdel.c \
					 ft_lstadd.c \
					 ft_strrcpy.c \
					 ft_realloc.c \
					 ft_eq_second.c \
					 ft_normalize.c \
					 ft_vectadd.c \
					 ft_vectsub.c \
					 ft_vrotate.c \
					 ft_coord_v.c \
					 ft_dot.c \
					 ft_vmult.c \
					 get_next_line.c \
					 ft_ftoa.c \
					 ft_uitoa_base.c \
					 ft_strcadd_left.c \
					 ft_strcadd_right.c \
					 ft_strcdel_left.c \
					 ft_strcdel_right.c \
					 ft_strinsert.c \
					 ft_strappend.c \
					 ft_strprepend.c \
					 ft_strlcpy.c \
					 ft_atoui_base.c \
					 ft_in_base.c \
					 ft_getpow.c \
					 ft_str_div_two.c \
					 ft_lftoa.c \
					 ft_str_mul_two.c \
					 ft_deci_bin.c \
					 ft_strrev.c \
					 free.c \
					 malloc.c \
					 realloc.c \
					 show_alloc_mem.c \
					 tools_glob.c \
					 ctrl_format.c \
					 dispatcher.c \
					 fl_dir.c \
					 fl_length.c \
					 fl_preci_number.c \
					 flags_detector.c \
					 ft_colors.c \
					 ft_dispatchc.c \
					 ft_dispatchd.c \
					 ft_dispatchf.c \
					 ft_itoa_printf.c \
					 ft_print.c \
					 tools_f.c \
					 tools.c \
					 tools_malloc.c \
					 printf_main.c \
					ft_list_par.c	\

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes


all: $(NAME)

$(NAME): $(OBJ)
	-@ar -r $@ $^ 2> /dev/null || true
	@ranlib $@
	@echo "LIBFT compilée."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	-@rm -fv $(OBJ) 2> /dev/null || true
	-@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	-@rm -fv $(NAME) 2> /dev/null || true

re: fclean all

.PHONY: all, clean, fclean, re