NAME	=	philo_bonus


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g3 -fsanitize=address
RM		=	rm -f


SRC		=	philo.c\
			philo_allocate.c\
			philo_dinner.c\
			philo_get_arg.c\
			philo_report.c\
			philo_state.c\
			philo_time.c\
			philo_wait.c\
			philo_work.c\
			ft_atou.c
SRC_DIR	=	src
SRC		:=	$(SRC:%=$(SRC_DIR)/%)
OBJ		=	$(SRC:%.c=%.o)

INCL	=	philo.h\
			philo_const.h\
			philo_type.h\
			philo_state.h
INCL_DIR=	include
INCL	:=	$(INCL:%=$(INCL_DIR)/%)

ifeq ($(DEBUG_FLAG), 1)
CFLAGS	+=	$(DEBUG)
endif

all: $(NAME)

debug:
	$(MAKE) clean
	$(MAKE) DEBUG_FLAG=1

$(NAME): $(INCL) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ): %.o: %.c $(INCL)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCL_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
