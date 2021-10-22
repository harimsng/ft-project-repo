# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 21:53:35 by hseong            #+#    #+#              #
#    Updated: 2021/10/22 21:53:38 by hseong           ###   ########.kr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

TARGET=libft.a

SRC_DIR:=srcs
SRCS:=ft_putchar.c ft_putstr.c ft_strcmp.c ft_swap.c ft_strlen.c
SRC_FILES:=$(SRCS:%=$(SRC_DIR)/%)

OBJS:=$(SRCS:%.c=%.o)
OBJ_FILES:=$(OBJS:%=$(SRC_DIR)/%)

HDR_DIR=includes
HDR=ft.h
HDR_FILES:=$(HDR:%=$(HDR_DIR)/%)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	ar rc $@ $(OBJ_FILES)

$(OBJ_FILES): %.o : %.c $(HDR_FILES) 
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm $(OBJ_FILES) 

fclean: clean
	rm $(TARGET)

re: fclean all
