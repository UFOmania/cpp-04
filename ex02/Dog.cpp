#include "Dog.hpp"

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog got Destroyed" << std::endl;
}
Dog::Dog() : Animal("Dog") 
{
    brain = new Brain();
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
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "barking !!!" << std::endl;
}