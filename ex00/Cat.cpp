#include "Cat.hpp"

Cat::~Cat()
{
    std::cout << "Cat got Destroyed" << std::endl;
}
Cat::Cat() : Animal("Cat") 
{
    std::cout << "Default Cat is Constrtucted" << std::endl;
}
Cat::Cat(const Cat &other)
{
    *this = other;
    std::cout << "Copy Cat is Constrtucted" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    type = other.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meoing !!!" << std::endl;
}