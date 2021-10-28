NAME=ft_hexdump

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRC_DIR=srcs
SRCS=ft_hexdump.c
SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJ_FILES=$(SRC_FILES:%.c=%.o)

HDR_DIR=includes
HDRS=ft_hexd.h
HDR_FILES=$(HDRS:%=$(HDR_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_FILES): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDR_DIR)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
