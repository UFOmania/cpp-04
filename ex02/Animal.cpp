#include "Animal.hpp"
#include <iostream>

Animal::~Animal()
{
    std::cout << "Animal " << type << " got Destroyed" << std::endl;
}

Animal::Animal() : type("Default")
{
    std::cout << "Default animal is Constrtucted" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
    std::cout << "Animal type " << type <<  " is Constrtucted" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Copy animal is Constrtucted" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
    type = other.type;
    return *this;
}


std::string Animal::getType() const
{
	return type;
}