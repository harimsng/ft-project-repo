NAME	= liblinkedlist.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= linked_list.c\
		  linked_list_io.c\
		  linked_list_dep.c\
		  linked_list_mergesort.c
OBJ		= $(SRC:%.c=%.o)

INCLUDE	= linked_list.h

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
