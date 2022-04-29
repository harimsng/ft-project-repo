NAME	=	philo_test


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3 -fsanitize=address


SRC		=
SRC_DIR	=	src
SRC		=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)

INCL	=
INCL_DIR=	include
INCL	=	$(INCL:%=$(INCL_DIR)/%)

ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	$(DEBUG)
endif

all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCL_DIR)

$(OBJ): %.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCL_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
