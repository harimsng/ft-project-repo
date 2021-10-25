# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 21:53:35 by hseong            #+#    #+#              #
#    Updated: 2021/10/25 14:57:06 by hseong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=libft.a

SRC_DIR=srcs
SRCS=ft_putchar.c ft_putstr.c ft_strcmp.c ft_swap.c ft_strlen.c
SRC_FILES=$(SRCS:%=$(SRC_DIR)/%)
OBJS=$(SRCS:%.c=%.o)
OBJ_FILES=$(OBJS:%.o=$(SRC_DIR)/%.o)

HDR_DIR=includes
HDR=ft.h
HDR_FILES:=$(HDR:%=$(HDR_DIR)/%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $(OBJ_FILES)

$(OBJ_FILES): %.o: %.c $(HDR_FILES) 
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJS): %.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $(SRC_DIR)/$@

clean:
	rm -f $(OBJ_FILES) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
