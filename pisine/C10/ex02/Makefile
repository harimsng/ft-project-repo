CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=ft_tail

SRC_DIR=srcs
SRCS=ft_tail.c ft_putstr.c ft_puterr.c ft_stoi.c ft_str_is_numeric.c\
	 ft_strlcpy.c
SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJS=$(SRCS:%.c=%.o)
OBJ_FILES=$(OBJS:%=$(SRC_DIR)/%)

HDR_DIR=includes
HDRS=ft.h
HDR_FILES=$(HDRS:%=$(HDR_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_FILES): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HDR_DIR)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
