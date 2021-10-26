CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=libft.a

SRC_DIR=srcs
SRCS=ft_putchar.c ft_putstr.c ft_strcmp.c ft_swap.c ft_strlen.c
SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJS=$(SRCS:%.c=%.o)
OBJ_FILES=$(OBJS:%.o=$(SRC_DIR)/%.o)

HDR_DIR=includes
HDR=ft.h
HDR_FILES:=$(HDR:%=$(HDR_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I./includes

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
