CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=ft_cat

SRC_DIR=srcs
SRCS=ft_cat.c ft_putstr.c ft_puterr.c
SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJS=$(SRCS:%.c=%.o)
OBJ_FILES=$(OBJS:%=$(SRC_DIR)/%)

HDR_DIR=includes
HDRS=ft.h
HDR_FILES=$(HDRS:%=$(HDR_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_FILES): %.o: %.c $(HDR_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS): %.o: $(SRC_DIR)/%.c $(HDR_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
