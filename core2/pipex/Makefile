NAME	= pipex


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g3 -fsanitize=address
RM		= rm -f


SRC		= pipex.c\
		  pipex_process.c\
		  pipex_initialize.c\
		  ft_execvpe.c\
		  ft_memset.c\
		  ft_split.c\
		  ft_utils.c
SRC_DIR	= src
SRC		:= $(SRC:%=$(SRC_DIR)/%)
OBJ		= $(SRC:%.c=%.o)


INCL	= pipex.h
INCL_DIR= include


ifeq ($(DEBUG_FLAG), 1)
CFLAGS += $(DEBUG)
CC		= clang
endif


all: $(NAME)

debug:
	$(MAKE) fclean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCL_DIR)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCL_DIR)

.PHONY: all clean fclean re debug

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
