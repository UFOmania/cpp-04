#include "Dog.hpp"

Dog::~Dog()
{
    std::cout << "Dog got Destroyed" << std::endl;
}
Dog::Dog() : Animal("Dog") 
{
    std::cout << "Default Dog is Constrtucted" << std::endl;
}
Dog::Dog(const Dog &other)
{
    *this = other;
    std::cout << "Copy Dog is Constrtucted" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    type = other.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "barking !!!" << std::endl;
}