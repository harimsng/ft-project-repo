NAME	=	push_swap


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g #-fsanitize=address #option for lldb


SRC		=	push_swap_mergesort_1.c\
			push_swap_mergesort_2.c\
			push_swap_inst_1.c\
			push_swap_inst_2.c\
			push_swap_inst_3.c\
			push_swap_utils_1.c\
			push_swap_utils_2.c\
			verify_args.c
SRCDIR	=	src
SRC		:=	$(SRC:%=$(SRCDIR)/%)
OBJ		=	$(SRC:%.c=%.o)


BNS_SRC	=	checker.c\
			check_inst.c\
			get_next_line.c\
			get_next_line_utils.c
BNS_DIR	=	checker
BNS_SRC	:=	$(BNS_SRC:%=$(BNS_DIR)/%)
BNS_OBJ	=	$(BNS_SRC:%.c=%.o)

INCLUDE	=	push_swap.h\
			dlinkedlist.h\
			ft_deque.h\
			checker.h\
			get_next_line.h
INCLDIR	=	include


LIB		=	ftdeque
LIBDIR	=	deque
LIBNAME	=	$(LIBDIR)/lib$(LIB).a

ifeq ($(DFLAG), 1)
CFLAGS += $(DEBUG)
endif

all: $(NAME)

bonus: ft_checker 

debug: 
	$(MAKE) fclean
	$(MAKE) DFLAG=1

$(NAME): $(OBJ) $(LIBNAME)
	$(CC) $(CFLAGS) -o $@ main.c $^ -I$(INCLDIR) -l$(LIB) -L$(LIBDIR)

$(LIBNAME):
	$(MAKE) -C $(LIBDIR)
	$(MAKE) -C $(LIBDIR) clean

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLDIR)

ft_checker: $(BNS_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCLDIR) -l$(LIB) -L$(LIBDIR)

$(BNS_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLDIR) -DBUFFER_SIZE=64

clean:
	@rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	@rm -f $(NAME) $(LIBNAME)

re: fclean all
	
.PHONY: all clean fclean re
