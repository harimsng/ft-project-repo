NAME	= libftdeque.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= dlinkedlist.c\
		  dlinkedlist_io.c\
		  dlinkedlist_cur.c\
		  dlinkedlist_mergesort.c\
		  ft_utils.c\
		  ft_deque_item.c\
		  ft_deque.c
OBJ		= $(SRC:%.c=%.o)

INCLUDE	= dlinkedlist.h\
		  ft_utils.h\
		  ft_deque.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
