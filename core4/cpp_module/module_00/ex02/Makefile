NAME	=	AccountBook


RM		=	rm -f


CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98
DEBUG	=	-g -fsanitize=address


SRC		=	Account.cpp\
			tests.cpp

OBJ		=	$(SRC:%.cpp=%.o)

ifeq ($(DEBUG_FLAG), 1)
CXXFLAGS+=	$(DEBUG)
COMPILE_MODE	=	DEBUG.flag
else
COMPILE_MODE	=	RELEASE.flag
endif


.PHONY: all debug clean fclean re

all: $(COMPILE_MODE)
	$(MAKE) $(NAME)

RELEASE.flag:
	$(MAKE) fclean
	touch RELEASE.flag

DEBUG.flag:
	$(MAKE) fclean
	touch DEBUG.flag

debug:
	$(MAKE) DEBUG_FLAG=1 all

clean:
	$(RM) $(OBJ)
	$(RM) DEBUG.flag RELEASE.flag

fclean: clean
	$(RM) $(NAME)

re: fclean all


$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
