#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::~Cat()
{
    std::cout << "Cat got Destroyed" << std::endl;
    delete brain;
}
Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat is Constrtucted" << std::endl;
    brain = new Brain();
}
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy Cat is Constrtucted" << std::endl;
    brain = NULL;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return *this;
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meowing !!!" << std::endl;
}