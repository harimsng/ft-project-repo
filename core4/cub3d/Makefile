NAME		=	cub3d


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3 -fsanitize=address
RM			=	rm -f


SRC			=	main.c\
				c3d_init.c\
				c3d_detect_wall.c\
				c3d_load_map.c\
				c3d_raycast.c\
				c3d_drawline.c\
				c3d_background.c\
				c3d_util.c\
				c3d_exit.c\
				c3d_hook.c\
				keymap/c3d_keymap_transl_mac.c\
				keymap/c3d_keymap_rotate_mac.c\
				get_next_line.c
SRC_DIR		=	src
SRC			:=	$(SRC:%=$(SRC_DIR)/%)
OBJ			=	$(SRC:%.c=%.o)


INCL		=	cub3d.h
INCL_DIR	=	include
INCL		:=	$(INCL:%=$(INCL_DIR)/%)


LIBFLAGS	=	-L.

LIBFTNAME	=	libft
LIBFT		=	libft.a
LIBFT_DIR	=	libft
LIBFLAGS	+=	-lft
LIBS		+=	LIBFT.lib


MLXNAME		=	mlx
LIBFLAGS	+=	-l$(MLXNAME)
ifeq ($(shell uname), Darwin)
SYSDEPS		=	-framework OpenGL -framework AppKit -lz
OBJDEPS		=	-DSYS_MAC
MLX			=	libmlx.dylib
MLX_DIR		=	mlx_darwin
$(shell cp $(MLX_DIR)/mlx.h include/mlx.h)
else
SYSDEPS		=	-lm -lXext -lX11 #-pthread
OBJDEPS		=
MLX			=	libmlx.a
MLX_DIR		=	mlx_linux
$(shell cp $(MLX_DIR)/mlx.h include/mlx.h)
endif
LIBS		+=	MLX.lib


ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	$(DEBUG)
endif


all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1 $(NAME)

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFLAGS) $(SYSDEPS)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCL_DIR) $(OBJDEPS)

$(LIBS): %.lib:
	@$(MAKE) -C $($*_DIR) all
	mv $($*_DIR)/$($*) .
#	cp $($*_DIR)/$($*NAME).h include/$($*NAME).h

clean:
	$(RM) $(OBJ)

fclean: clean $(LIBS:%=%.clean)
	$(RM) $($(LIBS:%.lib=%))
	$(RM) $(NAME)

$(LIBS:%=%.clean): %.lib.clean:
	$(RM) $($*)
	@$(MAKE) -C $($*_DIR) clean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean libclean re
