NAME=bsq

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRC_DIR=srcs
SRCS=ft_bsq.c ft_map.c ft_strcheck.c ft_free.c ft_putstr.c ft_strlen.c\
	 ft_putnbr.c ft_putchar.c ft_puterr.c ft_strccpy.c ft_solve.c
SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJ_FILES=$(SRC_FILES:%.c=%.o)

HDR_DIR=includes
HDRS=ft.h
HDR_FILES=$(HDRS:%=$(HDR_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ -I../$(HDR_DIR)

$(OBJ_FILES): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I../$(HDR_DIR)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
