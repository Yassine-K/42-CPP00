NAME = phonebook

SRC = PhoneBook.cpp

OBJ = ${SRC:.cpp=.o}

SUP = -std=c++98

WWW = -Wall -Wextra -Werror

%.o: %.cpp
	@c++ ${WWW} -c $< -o $@

all : ${NAME}

${NAME}: ${OBJ}
	@c++ $^ -o $@ ${SUP}

clean:
	@rm -rf ${OBJ}

fclean:
	@rm -rf ${OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re