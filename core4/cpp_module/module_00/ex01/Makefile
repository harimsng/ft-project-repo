NAME		=	myAwesomePhonebook

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++11
DEBUG_OPT	=	-g3 -fsanitize=address
IDIR		=	.

SDIR		=	.
SRC			=	main.cpp\
				PhoneBook.cpp\
				Contact.cpp

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
