FILENAME=$1
CLASSES=$(cat $FILENAME)
SRC_LIST=""

which gsed > /dev/null
if [ $? != "0" ]
then
SED=sed
else
SED=gsed
fi

for CLASS in $CLASSES
do
	SRC_LIST="\\
				$CLASS.cpp$SRC_LIST"
	touch $CLASS.hpp
	touch $CLASS.cpp
	HEADER_GUARD="$(echo $CLASS | $SED 's/[A-Z]/_&/g' | $SED 's/[a-z]/\U&/g' | $SED 's/$/_/')"

##### file contents
HEADER_CONTENT="#ifndef $HEADER_GUARD
#define $HEADER_GUARD

class	$CLASS
{
	$CLASS();
	~$CLASS();
	$CLASS(const $CLASS &obj);
	$CLASS &operator=(const $CLASS &obj);
};

#endif"
SOURCE_CONTENT="#include \"$CLASS.hpp\"

$CLASS::$CLASS()
{
}

$CLASS::~$CLASS()
{
}

$CLASS::$CLASS(const $CLASS &obj)
{
	(void)obj;
}

$CLASS &$CLASS::operator=(const $CLASS &obj)
{
	(void)obj;
	return *this;
}"
#####

	printf '%b\n' "$HEADER_CONTENT" > $CLASS.hpp
	printf '%b\n' "$SOURCE_CONTENT" > $CLASS.cpp
done

MAKEFILE_CONTENT="NAME		=	$FILENAME


CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
DEBUGFLAGS	=	-g -fsanitize=address
RM			=	rm -f


SRC			=	main.cpp$SRC_LIST
OBJ			=	\$(SRC:%.cpp=%.o)

ifeq (\$(DEBUG_MODE), 1)
CXXFLAGS	+=	\$(DEBUGFLAGS)
COMPILE_MODE=	DEBUG.mode
else
COMPILE_MODE=	RELEASE.mode
endif


.PHONY: all debug clean fclean re

all: \$(COMPILE_MODE)
	\$(MAKE) \$(NAME)

RELEASE.mode:
	\$(MAKE) fclean
	touch RELEASE.mode

DEBUG.mode:
	\$(MAKE) fclean
	touch DEBUG.mode

debug:
	\$(MAKE) DEBUG_MODE=1 all

clean:
	\$(RM) \$(OBJ)
	\$(RM) RELEASE.mode DEBUG.mode

fclean: clean
	\$(RM) \$(NAME)

re: fclean
	\$(MAKE) all

\$(NAME): \$(OBJ)
	\$(CXX) \$(CXXFLAGS) -o \$@ \$^

\$(OBJ): %.o: %.cpp
	\$(CXX) \$(CXXFLAGS) -c -o \$@ \$<"
printf '%b\n' "$MAKEFILE_CONTENT" > Makefile_temp
cat Makefile_temp | sed 's/ $//' > Makefile
rm Makefile_temp
touch .vimspector.json
VIMSPECTOR="{
  \"configurations\": {
  \"C - Launch\": {
    \"adapter\": \"CodeLLDB\",
    \"configuration\": {
      \"name\": \"Cpp: Launch current file\",
      \"type\": \"lldb\",
      \"request\": \"launch\",
      \"externalConsole\": false,
      \"logging\": {
        \"engineLogging\": true
      },
      \"stopOnEntry\": true,
      \"stopAtEntry\": true,
      \"debugOptions\": [],
      \"MIMode\": \"lldb\",
      \"cwd\" : \"${cwd}\",
      \"args\" : [],
      \"program\": \"$FILENAME\"
    }
  }
  }
}"

printf '%b\n' "$VIMSPECTOR" > .vimspector.json
