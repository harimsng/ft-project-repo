NAME	= libdoublyll.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= doublyll.c\
		  doublyll_io.c\
		  doublyll_cur.c\
		  doublyll_mergesort.c\
		  doublyll_dep.c
OBJ		= $(SRC:%.c=%.o)

INCLUDE	= doublyll.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	cp $(NAME) ..
	cp $(INCLUDE) ..

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
