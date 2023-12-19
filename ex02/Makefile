NAME =	Form2.0

SRC =	${addprefix sources/, \
			main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
		}

OBJ		= ${SRC:sources/%.cpp=objects/%.o}

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g3

${NAME}: ${OBJ} includes/*.hpp
		 ${CC} ${FLAGS} -o ${NAME} ${OBJ}

objects/%.o: sources/%.cpp
			mkdir -p $(dir $@)
			${CC} ${FLAGS} -c -o $@ $^

all:	${NAME}

clean:
		rm -rf objects

fclean:	clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: clean fclean all re