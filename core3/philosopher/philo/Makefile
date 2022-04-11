NAME	=	philo


CFLAGS	=	-Wall -Wextra -Werror -O3
CC		=	gcc
RM		=	rm -f
DEBUG	=	-g3 -fsanitize=address


SRC		=	philo.c\
			philo_arg.c\
			philo_dinner.c\
			philo_alloc.c\
			philo_report.c\
			philo_state.c\
			philo_access.c\
			philo_time.c\
			philo_watch.c\
			ft_atoi.c
SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)

OBJ		=	$(SRC:%.c=%.o)

INCL	=	philo.h\
			philo_type.h\
			philo_const.h\
			philo_utils.h
INCL_DIR=	include

ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	$(DEBUG)
endif

ifeq ($(shell uname), Linux)
CFLAGS	+=	-pthread
endif

all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCL_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
