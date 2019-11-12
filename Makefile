ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

GCC= gcc
CFLAGS= -Wall -Wextra -Werror -FPIC

NAME= ft_malloc_$(HOSTTYPE).so
LINK= ft_malloc.so
LIBFT= $(LIBFT_DIR)libft.a
HEADERS = -I ./include -I $(LIBFT_DIR)

SRC_DIR= ./srcs/

SRC_DIR_FREE = free/
SRC_DIR_MALLOC = malloc/
SRC_DIR_REALLOC = realloc/


FILENAMES =		free malloc realloc show_alloc_mem
LIBRARIES =		-L$(LIBFT_DIR) -lft
OBJ_DIR= ./obj/
LIBFT_DIR =		./libft/
LIBS = libft
OBJ_PATHS :=	$(addprefix $(OBJ_DIR),$(addsuffix .o,$(FILENAMES)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PATHS)
	$(CC) $(OBJ_PATHS) $(HEADERS) $(LIBRARIES) -shared -o $(NAME)
	@rm -f $(LINK)
	ln -s $(NAME) $(LINK)

$(OBJ_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

clean:
	-rm -rf obj  2> /dev/null || true
	make -C $(LIBS) clean 2> /dev/null || true

fclean: clean
	-rm -rf $(NAME) $(LINK)
	make -C $(LIBS) fclean 2> /dev/null || true

re: fclean all

.PHONY: all $(NAME)
