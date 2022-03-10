NAME	= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g3 -fsanitize=address
RM		= rm -f


SRC		=
SRC_DIR	= src
OBJ		= $(SRC:%.c=%.o)

INCL	= 
INCL_DIR= include

ifeq (DEBUG_FLAG, 1)
	CFLAGS += DEBUG
endif

all: $(NAME)

debug:
	$(MAKE) fclean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re debug

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
