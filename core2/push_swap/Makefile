NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	push_swap.c\
			verify_args.c

OBJ		=	$(SRC:%.c=%.o)

INCLUDE	=	push_swap.h\
			ft_deque.h

LIB		=	ftdeque
LIBDIR	=	deque

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ main.c $^ -I. -l$(LIB) -L$(LIBDIR)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
