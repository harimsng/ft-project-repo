CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c\
	ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_strlen.c\
	ft_isspace.c ft_ishex.c\
	ft_abs.c ft_swap.c\
	ft_memset.c ft_memcpy.c\
	ft_atoi.c ft_atoi_ptr.c\
	ft_htoi.c ft_strchr.c\
	ft_toupper.c\
	ft_split.c ft_itoa.c\
	ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRC:%.c=%.o)

HDR = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ -I.

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
