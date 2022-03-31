NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3 -fsanitize=address
OPTI	=	-O3
RM		=	rm -f


# object & source files
SRC		=	main.c\
			fdf_init.c\
			fdf_hook.c\
			fdf_plot.c\
			fdf_projection.c\
			fdf_drawline.c\
			fdf_aa_drawline.c\
			fdf_wireframe.c\
			wireframe/fdf_wireframe_diag.c\
			wireframe/fdf_wireframe_diag2.c\
			wireframe/fdf_wireframe_normal.c\
			wireframe/fdf_wireframe_normal2.c\
			keymap/fdf_keymap_transl_mac.c\
			keymap/fdf_keymap_rotate_mac.c\
			keymap/fdf_keymap_rotate2_mac.c\
			keymap/fdf_keymap_scale_mac.c\
			keymap/fdf_keymap_projection_mac.c\
			fdf_color.c\
			fdf_load_map.c\
			fdf_manage_map.c\
			fdf_interface.c\
			fdf_utils.c\
			get_next_line.c

SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)


# header files
INCL	=	fdf.h\
			fdf_const.h\
			fdf_type.h\
			fdf_keymap.h\
			mlx.h\
			get_next_line.h\
			libft.h
INCL_DIR=	include


# library
LIB_NAME=	libmlx.dylib
LIB		=	mlx
LIB_DIR	=	library

LFT_NAME=	libft.a
LFT		=	ft
LFT_DIR	=	libft

ifeq ($(DEBUG_FLAG), 1)
CFLAGS +=	$(DEBUG)
endif

ifeq ($(OPTI_FLAG), 1)
CFLAGS +=	$(OPTI)
endif


all: $(NAME)

opti:
	$(MAKE) clean
	$(MAKE) OPTI_FLAG=1

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

norm:
	norminette $(INCL_DIR)
	norminette $(SRC_DIR)


$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_NAME) .

$(LFT_NAME):
	$(MAKE) -C $(LFT_DIR)
	cp $(LFT_DIR)/$(LFT_NAME) .


$(NAME): $(LFT_NAME) $(LIB_NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -l$(LIB) -L.\
		-framework OpenGL -framework AppKit -lz\
		-l$(LFT)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCL_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB_NAME) $(LFT_NAME)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(LFT_DIR) clean

re: fclean all

.PHONY: all clean fclean re debug norm
