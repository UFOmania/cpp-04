#include "Cat.hpp"

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat got Destroyed" << std::endl;
}
Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
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
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "barking !!!" << std::endl;
}