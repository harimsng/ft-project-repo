NAME		=	megaphone

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
DEBUG_OPT	=	-g3 -fsanitize=address

SDIR		=	.
SRC			=	megaphone.cpp

ODIR		=	.
OBJ			=	$(SRC:%.cpp=%.o)

ifeq ($(DEBUG_FLAG), 1)
CXXFLAGS	+=	$(DEBUG_OPT)
endif

all: $(NAME)

debug:
	$(MAKE) DEBUG_FLAG=1 all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
