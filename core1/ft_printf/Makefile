CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a 
LIB		= libft/libft.a

SRC_DIR	= src
SRCS	= print_char.c		print_string.c\
		  print_pointer.c	print_integer.c\
	  	  print_unsigned.c  print_lowhex.c\
		  print_uphex.c		print_percent.c

LIB_DIR = libft
LIB_SRC = ft_strchr.c		ft_strlen.c\
		  ft_strlcpy.c

SRC_DEP	= $(SRCS:%=$(SRC_DIR)/%)
SRC_DEP += $(LIB_SRC:%=$(LIB_DIR)/%)
SRC_DEP += ft_printf.c

HDRS	= ft_printf.h

OBJS	= $(SRC_DEP:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -I./$(LIB_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
