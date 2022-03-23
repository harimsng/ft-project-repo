NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3 -fsanitize=address
RM		=	rm -f


# object & source files
SRC		=	main.c\
			fdf_init.c\
			fdf_loop.c\
			fdf_drawline.c\
			fdf_keyinput.c\
			fdf_parser.c\
			fdf_point.c\
			ft_memset.c\
			ft_putnbr_fd.c\
			ft_utils.c\
			ft_split.c\
			ft_atoi.c\
			get_next_line.c

SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)


# header files
INCL	=	fdf.h\
			mlx.h\
			get_next_line.h\
			libft.h
INCL_DIR=	include


# library
LIB_NAME=	libmlx.dylib
LIB		=	mlx
LIB_DIR	=	library

ifeq ($(DEBUG_FLAG), 1)
CFLAGS +=	$(DEBUG)
endif



all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

norm:
	norminette $(INCL_DIR)
	norminette $(SRC_DIR)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_NAME) .

$(NAME): $(LIB_NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -l$(LIB) -L.\
		-framework OpenGL -framework AppKit -lz

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCL_DIR) -DBUFFER_SIZE=256

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB)
	$(MAKE) -C $(LIB_DIR) clean

re: fclean all

.PHONY: all clean fclean re debug norm
