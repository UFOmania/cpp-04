#include "Cat.hpp"
#include <iostream>

Cat::~Cat()
{
    std::cout << "Cat got Destroyed" << std::endl;
}
Cat::Cat() : Animal("Cat") 
{
    std::cout << "Default Cat is Constructed" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy Cat is Constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
    Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meoing !!!" << std::endl;
}