NAME=libft.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS=$(SRCS:%.c=%.o)

HDR_DIR=includes
HDR=includes/ft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HDR_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

