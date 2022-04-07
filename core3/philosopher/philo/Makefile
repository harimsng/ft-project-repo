NAME	=	philo


CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
RM		=	rm -f
DEBUG	=	-g3 -fsanitize=address


SRC		=	philo.c\
			philo_arg.c\
			philo_dinner.c\
			philo_alloc.c\
			philo_report.c\
			philo_state.c\
			philo_time.c\
			ft_atoi.c

OBJ		=	$(SRC:%.c=%.o)

INCL	=	philo.h\
			philo_type.h\
			philo_const.h\
			philo_utils.h

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
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
