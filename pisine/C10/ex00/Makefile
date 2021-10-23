CC=gcc
CFLAGS=-Wall -Wextra -Werror

TARGET=ft_display_file

SRC_DIR=srcs
HDR_DIR=includes

SRCS=ft_display_file.c ft_putstr.c ft_putnbr.c
OBJS=$(SRCS:%.c=%.o)
HDRS=ft.h

SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJ_FILES=$(OBJS:%=$(SRC_DIR)/%)
HDR_FILES=$(HDRS:%=$(HDR_DIR)/%)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FILES): %.o : %.c $(HDR_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(TARGET)

re: fclean all
