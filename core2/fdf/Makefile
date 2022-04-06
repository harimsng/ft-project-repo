NAME	=	fdf

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
DEBUG	=	-g3 -fsanitize=address
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
			keymap/fdf_keymap_transl2_mac.c\
			keymap/fdf_keymap_rotate_mac.c\
			keymap/fdf_keymap_rotate2_mac.c\
			keymap/fdf_keymap_scale_mac.c\
			keymap/fdf_keymap_projection_mac.c\
			keymap/fdf_keymap_height_mac.c\
			keymap/fdf_keymap_flag_mac.c\
			fdf_color.c\
			fdf_load_map.c\
			fdf_manage_map.c\
			fdf_interface.c\
			fdf_utils.c\
			fdf_terminate.c\
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
INCL	:=	$(INCL:%=$(INCL_DIR)/%)


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

$(LFT_NAME):
	$(MAKE) -C $(LFT_DIR)
	cp $(LFT_DIR)/$(LFT_NAME) .


$(NAME): $(LFT_NAME) $(LIB_NAME) $(OBJ) $(INCL)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -l$(LIB) -L. -l$(LFT) \
		-framework AppKit -framework OpenGL -lz

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCL_DIR)

clean:
	$(RM) $(OBJ) $(BNS_OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB_NAME) $(LFT_NAME)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(LFT_DIR) clean

re: fclean all

.PHONY: all clean fclean re debug norm
