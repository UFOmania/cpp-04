#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << type << " got Destroyed" << std::endl;
}

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "Default Wronganimal is Constrtucted" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout << "WrongAnimal type " << type <<  " is Constrtucted" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "Copy Wronganimal is Constrtucted" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
		return *this;
    type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout<<"Wronganimal sound!!!\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}