TARGET=rush-02

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRC_DIR=srcs
HDR_DIR=includes

SRCS=$(shell find $(SRC_DIR) -name '*.c')
OBJS=$(SRCS:%.c=%.o)
HDRS=$(shell find $(HDR_DIR) -name '*.h')

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean fclean all re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
