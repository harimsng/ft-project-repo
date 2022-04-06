NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g -fsanitize=address #option for lldb

# MANDATORY
SRC		=	main.c\
			push_swap_mergesort_1.c\
			push_swap_mergesort_2.c\
			push_swap_divide.c\
			push_swap_inst_1.c\
			push_swap_inst_2.c\
			push_swap_inst_3.c\
			push_swap_utils.c\
			push_swap_optimizer.c\
			push_swap_block.c\
			push_swap_output.c\
			verify_args.c
SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)

# BONUS
BNS_NAME=	checker
BNS_SRC	=	checker.c\
			check_inst.c\
			push_swap_inst_1.c\
			push_swap_inst_2.c\
			push_swap_inst_3.c\
			push_swap_utils.c\
			push_swap_output.c\
			verify_args.c\
			get_next_line.c\
			get_next_line_utils.c
BNS_DIR	=	checker_dir
BNS_SRC	:=	$(BNS_SRC:%=$(BNS_DIR)/%)
BNS_OBJ	=	$(BNS_SRC:%.c=%.o)

# HEADER
INCLUDE	=	push_swap.h\
			dlinkedlist.h\
			ft_deque.h\
			checker.h\
			get_next_line.h
INCL_DIR=	include

# LIBRARY
LIB		=	ftdeque
LIB_DIR	=	deque
LIBNAME	=	$(LIB_DIR)/lib$(LIB).a

ifeq ($(DFLAG), 1)
CFLAGS += $(DEBUG)
CC		= clang
endif

# TARGETS
all: $(NAME)

bonus: $(BNS_NAME)

debug: 
	@echo "debug mode"
	@$(MAKE) fclean
	@$(MAKE) DFLAG=1

norm:
	@norminette $(LIB_DIR) $(INCL_DIR) $(SRC_DIR) $(BNS_DIR)

$(LIBNAME):
	@echo "library ftdeque compiling"
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(LIB_DIR) clean

$(NAME): $(OBJ) $(LIBNAME)
	@echo "push_swap compiling"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -I$(INCL_DIR) -l$(LIB) -L$(LIB_DIR)

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCL_DIR)

$(BNS_NAME): $(BNS_OBJ) $(LIBNAME)
	@echo "checker compiling"
	@$(CC) $(CFLAGS) -o $@ $^ -I$(INCL_DIR) -l$(LIB) -L$(LIB_DIR)

$(BNS_OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCL_DIR) -DBUFFER_SIZE=64

clean:
	@rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	@rm -f $(NAME) $(LIBNAME) $(BNS_NAME)

re: fclean all
	
.PHONY: all clean fclean re
