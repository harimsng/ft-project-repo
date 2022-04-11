NAME	=	philo_bonus


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3 -fsanitize=address
RM		=	rm -f


SRC		=	philo.c
SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)

INCL	=	philo_bonus.h
INCL_DIR=	include
INCL	:=	$(INCL:%=$(INCL_DIR)/%)

ifeq ($(DEBUG), 1)
CFLAGS	+=	$(DEBUG)
endif

all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG=1

$(NAME): $(INCL) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ): %.o: %.c $(INCL)
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCL_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
