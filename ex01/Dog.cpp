#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::~Dog()
{
    std::cout << "Dog got Destroyed" << std::endl;
    delete brain;
}
Dog::Dog() : Animal("Dog") 
{
    std::cout << "Default Dog is Constrtucted" << std::endl;
    brain = new Brain();
}
Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy Dog is Constrtucted" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "barking !!!" << std::endl;
}