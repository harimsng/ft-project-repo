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

bonus: all ft_checker 

debug: 
	@echo "debug mode"
	@$(MAKE) fclean
	@$(MAKE) DFLAG=1

$(NAME): $(OBJ) $(LIBNAME)
	@echo "push_swap compiling"
	@$(CC) $(CFLAGS) -o $@ main.c $^ -I$(INCLDIR) -l$(LIB) -L$(LIBDIR)

$(LIBNAME):
	@echo "library ftdeque compiling"
	@$(MAKE) -C $(LIBDIR)
	@$(MAKE) -C $(LIBDIR) clean

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLDIR)

ft_checker: $(BNS_OBJ) $(OBJ)
	@echo "ft_checker compiling"
	@$(CC) $(CFLAGS) $^ -o $@ -I$(INCLDIR) -l$(LIB) -L$(LIBDIR)

$(BNS_OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLDIR) -DBUFFER_SIZE=64

clean:
	@rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	@rm -f $(NAME) $(LIBNAME) ft_checker

re: fclean all
	
.PHONY: all clean fclean re
