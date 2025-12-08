src= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
obj = $(src:.cpp=.o)
flags = -Wall -Wextra -Werror -std=c++98  #-fsanitize=address -g3
NAME= Animal

all: $(NAME)

$(NAME): $(obj)
	c++ $(flags) $(obj) -o $@

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp Brain.hpp
	c++ $(flags) -o $@ -c $<

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all