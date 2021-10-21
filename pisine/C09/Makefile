CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC_DIR:=srcs
SRCS:=ft_putchar.c ft_putstr.c ft_strcmp.c ft_swap.c ft_strlen.c
OBJS:=$(patsubst %.c,%.o,$(SRCS))
SRC_FILES:=$(patsubst %,$(SRC_DIR)/%,$(SRCS))
OBJ_FILES:=$(patsubst %,$(SRC_DIR)/%,$(OBJS))
HDR_DIR=includes
HDR=ft.h
TARGET=libft.a

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	ar rc $@ $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES) $(HDR)
	$(CC) $(CLAGS) $< -c -o $@
