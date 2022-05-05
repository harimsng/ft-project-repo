NAME	=	minishell


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3 -fsanitize=address
RM		=	rm -f


SRC		=	minishell.c\
			memory_management.c
SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)


INCL	=	minishell.h
INCL_DIR=	include
INCL	:=	$(INCL:%=$(INCL_DIR)/%)


LIB		=	libft.a
LIB_NAME=	ft
LIB_DIR	=	library


all: $(NAME)

fast:
	$(MAKE) all -j 8

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline -L$(LIB_DIR) -l$(LIB_NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCL_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) .

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB)
	$(MAKE) -C $(LIB_DIR) clean

re: fclean
	$(MAKE) all -j 8

.PHONY: all clean fclean re
