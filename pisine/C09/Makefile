CFLAGS = "-Wall -Wextra -Werror"
CC = gcc
OBJ_FILES = ft_putchar.o ft_putstr.o ft_strcmp.o ft_swap.o ft_strlen.o
SRC_FILES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_swap.c ft_strlen.c
HEADER_FILES = ft.h

$(OBJ_FILES): %.o: %.c

libft.a: ./srcs/$(OBJECT_FILES) ./includes/$(HEADER_FILES)
	ar rc $@ $^ 

$(OBJECT_FILES): ./srcs/$(SOURCE_FILES)
	$(CC) $(CC_FLAGS) $^ -c

