#include "Animal.hpp"

Animal::~Animal()
{
    std::cout << "animal " << type << " got Destroyed" << std::endl;
}
Animal::Animal()
{
    type = "Creeper";
    std::cout << "Default animal is Constrtucted" << std::endl;
}
Animal::Animal(const std::string &type)
{
    this->type = type;
    std::cout << "animal type " << type <<  " is Constrtucted" << std::endl;
}
Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Copy animal is Constrtucted" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    type = other.type;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout<<"booom!!!\n";
}