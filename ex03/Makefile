src= AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
obj = $(src:.cpp=.o)
flags = -Wall -Wextra -Werror -MMD -std=c++98
deps = $(src:.cpp=.d)
NAME= app

all: $(NAME)

$(NAME): $(obj)
	c++ $(flags) $(obj) -o $@

%.o: %.cpp
	c++ $(flags) -o $@ -c $<

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(deps)