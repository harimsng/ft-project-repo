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


INCL	=	minishell.h\
			doubly_linked_list.h\
			libft.h
INCL_DIR=	include
INCL	:=	$(INCL:%=$(INCL_DIR)/%)


LIBFT	=	libft.a
LIBFT_NAME=	ft
LIBFT_DIR=	libft
LIBS	+=	LIBFT.lib


DLLIST	=	libdlinkedlist.a
DLLIST_NAME=dlinkedlist
DLLIST_DIR=	doubly_linked_list
LIBS	+=	DLLIST.lib


all: $(NAME)

fast:
	$(MAKE) all -j 8

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline -L$(LIBFT_DIR) -l$(LIBFT_NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCL_DIR)

$(LIBS): %.lib:
	@$(MAKE) -C $($*_DIR) all
	mv $($*_DIR)/$($*) .

clean:
	$(RM) $(OBJ)

fclean: clean $(LIBS:%=%.clean)
	$(RM) $($(LIBS:%.lib=%))
	$(RM) $(NAME)

$(LIBS:%=%.clean): %.lib.clean:
	$(RM) $($*)
	@$(MAKE) -C $($*_DIR) fclean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean libclean re
