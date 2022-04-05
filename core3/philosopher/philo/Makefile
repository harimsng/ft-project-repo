NAME	=	philo


CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
RM		=	rm -f
DEBUG	=	-g3 -fsanitize=address


SRC		=	philo.c

OBJ		=	$(SRC:%.c=%.o)

INCL	=	philo.h

ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	$(DEBUG)
endif

all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
