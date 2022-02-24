NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g #-fsanitize=address

SRC		=	push_swap_mergesort_1.c\
			push_swap_mergesort_2.c\
			push_swap_inst_1.c\
			push_swap_inst_2.c\
			push_swap_inst_3.c\
			push_swap_utils.c\
			verify_args.c
#			push_swap_quicksort.c\

SRCDIR	=	src
SRC		:=	$(SRC:%=$(SRCDIR)/%)

OBJ		=	$(SRC:%.c=%.o)

INCLUDE	=	push_swap.h\
			dlinkedlist.h\
			ft_deque.h

INCLDIR	=	include

LIB		=	ftdeque
LIBDIR	=	deque
LIBNAME	=	$(LIBDIR)/lib$(LIB).a

ifeq ($(DFLAG), 1)
CFLAGS += $(DEBUG)
endif

all: $(NAME)

debug: 
	$(MAKE) DFLAG=1

$(NAME): $(OBJ) $(LIBNAME)
	$(CC) $(CFLAGS) -o $@ main.c $^ -I$(INCLDIR) -l$(LIB) -L$(LIBDIR)

$(LIBNAME):
	$(MAKE) -C $(LIBDIR)
	$(MAKE) -C $(LIBDIR) clean

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIBNAME)

re: fclean all
	
.PHONY: all clean fclean re
