NAME	= libdlinkedlist.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= dlinkedlist.c\
		  dlinkedlist_io.c\
		  dlinkedlist_cur.c\
		  dlinkedlist_mergesort.c\
		  dlinkedlist_dep.c
OBJ		= $(SRC:%.c=%.o)

INCLUDE	= dlinkedlist.h

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
