FILENAME=$1
CLASSES=$(cat $FILENAME)
SRC_LIST=""

for CLASS in $CLASSES
do
	SRC_LIST="\t\t\t\t$CLASS\n$SRC_LIST"
	touch $CLASS.hpp
	touch $CLASS.cpp
	HEADER_GUARD="$(echo $CLASS | gsed 's/[A-Z]/_&/g' | gsed 's/[a-z]/\U&/g' | gsed 's/$/_/')"

##### file contents
HEADER_CONTENT="
#ifndef $HEADER_GUARD
\n#define $HEADER_GUARD
\n
\nclass	$CLASS
\n{
\n\t$CLASS();
\n\t~$CLASS();
\n\t$CLASS(const $CLASS &obj);
\n\tconst $CLASS &operator=(const $CLASS &obj);
\n};
\n
\n#endif"
SOURCE_CONTENT="
#include \"$CLASS.hpp\"
\n
\n$CLASS::$CLASS()
\n{
\n}
\n
\n$CLASS::~$CLASS()
\n{
\n}
\n
\n$CLASS::$CLASS(const $CLASS &obj)
\n{
\n}
\n
\nconst $CLASS &$CLASS::operator=(const $CLASS &obj)
\n{
\n\treturn *this;
\n}"
#####

	echo -e $HEADER_CONTENT > $CLASS.hpp
	echo -e $SOURCE_CONTENT > $CLASS.cpp
done

MAKEFILE_CONTENT="
NAME\t\t=\t
\n
\n
\nCXX\t\t\t=\tc++
\nCXXFLAGS\t=\t-Wall -Wextra -Werror -std=c++98
\nDEBUGFLAGS\t=\t-g -fsanitize=address
\nRM\t\t\t=\trm -f
\n
\n
\nSRC\t\t\t=\tmain.cpp
\n$SRC_LIST
\nOBJ\t\t\t=\t\$(SRC:%.cpp=%.o)
\n
\nifeq (\$(DEBUG_MODE), 1)
\nCXXFLAGS\t+=\t\$(DEBUGFLAGS)
\nCOMPILE_MODE=\tDEBUG.mode
\nelse
\nCOMPILE_MODE=\tRELEASE.mode
\nendif
\n
\n
\n.PHONY: all debug clean fclean re
\n
\nall: \$(COMPILE_MODE)
\n\t\$(MAKE) \$(NAME)
\n
\nRELEASE.mode:
\n\t\$(MAKE) fclean
\n\ttouch RELEASE.mode
\n
\nDEBUG.mode:
\n\t\$(MAKE) fclean
\n\ttouch DEBUG.mode
\n
\ndebug:
\n\t\$(MAKE) DEBUG_MODE=1 all
\n
\nclean:
\n\t\$(RM) \$(OBJ)
\n\t\$(RM) RELEASE.mode DEBUG.mode
\n
\nfclean: clean
\n\t\$(RM) \$(NAME)
\n
\nre: fclean
\n\t\$(MAKE) all
\n
\n\$(NAME): \$(OBJ)
\n\t\$(CXX) \$(CXXFLAGS) -o \$@ \$^
\n
\n\$(OBJ): %.o: %.cpp
\n\t\$(CXX) \$(CXXFLAGS) -c -o \$@ \$<"
echo -e $MAKEFILE_CONTENT > Makefile
