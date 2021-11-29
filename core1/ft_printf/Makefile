CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= ft_printf
SRC_DIR	= srcs
SRCS	= ft_printf.c
OBJS	= $(SRCS:%.c=%.o)

HDR_DIR	= includes
HDRS	= ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
