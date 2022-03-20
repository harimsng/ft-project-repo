NAME	= fdf

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g3 -fsanitize=address
RM		= rm -f


# object & source files
SRC		= main.c\
		  fdf_key.c\
		  ft_memset.c

SRC_DIR	= src
SRC		:= $(SRC:%=$(SRC_DIR)/%)
OBJ		= $(SRC:%.c=%.o)


# header files
INCL	=	fdf.h\
			mlx.h\
			libft.h
INCL_DIR= include


# library
LIB		= mlx
LIB_DIR	= library

ifeq ($(DEBUG_FLAG), 1)
CFLAGS += $(DEBUG)
endif



all: $(NAME)

debug:
	$(MAKE) DEBUG_FLAG=1

norm:
	norminette $(INCL_DIR)
	norminette $(SRC_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/lib$(LIB).dylib .

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -l$(LIB) -L.\
		-framework OpenGL -framework AppKit -lz

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCL_DIR) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB)
	$(MAKE) -C $(LIB_DIR) clean

re: fclean all

.PHONY: all clean fclean re debug norm
