NAME = Span
CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -fsanitize=address -g3

CPPFILES= ${wildcard *.cpp}
OFILES=${CPPFILES:.cpp=.o}

all:${NAME}

${NAME}: ${OFILES}
	${CXX} ${CXXFLAGS} $^ -o $@

clean:
	rm -f ${OFILES}
fclean: clean
	rm -f ${NAME}
re: fclean all