src= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
obj = $(src:.cpp=.o)
flags = -Wall -Wextra -Werror -MMD -std=c++98
deps = $(src:.cpp=.d)

NAME= Animal

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