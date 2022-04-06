NAME	=	arvis

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
DEBUG	=	-g -fsanitize=address
RM		=	rm -f

SRC		=
SRC_DIR	=	src
SRC		=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)

INCL	=
INCL_DIR=	include

LIB_NAME=	mlx
ifeq ($(shell uname), "Darwin")
LIB		=	libmlx.dylib
else
LIB		=	libmlx.a
endif
LIB_DIR	=	library

ifeq ($(DEBUG_FLAG), 1)
CFLAG	+=	$(DEBUG)
endif

all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(LIB) $(OBJ) $(INCL)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIB_DIR) -l$(LIB) -I$(INCL_DIR)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ _I$(INCL_DIR)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIB_NAME) .

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB_NAME) $(NAME)
	$(MAKE) -C $(LIB_DIR) clean

re: fclean all

.PHONY: all clean fclean re debug
