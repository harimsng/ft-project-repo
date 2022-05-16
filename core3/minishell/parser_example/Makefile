# Makefile

FILES = Lexer.c Parser.c Expression.c main.c
CC = g++
CFLAGS = -g -ansi

test: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o test

Lexer.c: Lexer.l
	/Users/hseong/.brew/Cellar/flex/2.6.4_2/bin/flex Lexer.l

Parser.c: Parser.y Lexer.c
	/Users/hseong/.brew/Cellar/bison/3.8.2/bin/bison Parser.y

clean:
	rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h test
