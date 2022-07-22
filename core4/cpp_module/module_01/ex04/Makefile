NAME		=	miniSed


CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
DEBUGFLAGS	=	-g -fsanitize=address
RM			=	rm -f


SRC			=	main.cpp\
				Filehandler.cpp
OBJ			=	$(SRC:%.cpp=%.o)

ifeq ($(DEBUG_MODE), 1)
CXXFLAGS	+=	$(DEBUGFLAGS)
COMPILE_MODE=	DEBUG.mode
else
COMPILE_MODE=	RELEASE.mode
endif


.PHONY: all debug clean fclean re

all: $(COMPILE_MODE)
	$(MAKE) $(NAME)

RELEASE.mode:
	$(MAKE) fclean
	touch RELEASE.mode

DEBUG.mode:
	$(MAKE) fclean
	touch DEBUG.mode

debug:
	$(MAKE) DEBUG_MODE=1 all

clean:
	$(RM) $(OBJ)
	$(RM) RELEASE.mode DEBUG.mode

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
