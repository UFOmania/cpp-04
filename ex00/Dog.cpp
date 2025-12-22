#include "Dog.hpp"
#include <iostream>

Dog::~Dog()
{
    std::cout << "Dog got Destroyed" << std::endl;
}
Dog::Dog() : Animal("Dog") 
{
    std::cout << "Default Dog is Constrtucted" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy Dog is Constrtucted" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "barking !!!" << std::endl;
}