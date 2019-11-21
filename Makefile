ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

GCC= gcc
CFLAGS= -Wall -Wextra -Werror -fPIC -g

NAME= ft_malloc_$(HOSTTYPE).so
LINK= ft_malloc.so
HEADERS = -I ./includes/

SRC_DIR= ./srcs/

FILENAMES =		free malloc realloc show_alloc_mem tools_glob
OBJ_DIR= ./obj/
OBJ_PATHS :=	$(addprefix $(OBJ_DIR),$(addsuffix .o,$(FILENAMES)))

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	$(CC) $(OBJ_PATHS) $(HEADERS) -shared -o $(NAME)
	@rm -f $(LINK)
	ln -s $(NAME) $(LINK)

$(OBJ_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(HEADERS) $< -o $@

$(LIBFT):
	(cd && make)

clean:
	-rm -rf obj  2> /dev/null || true

fclean: clean
	-rm -rf $(NAME) $(LINK)

re: fclean all

.PHONY: all $(NAME)
