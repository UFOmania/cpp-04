#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::~Ice()
{}
Ice::Ice()
{
    _type = "ice";
}
Ice::Ice(const Ice & other) : AMateria("ice")
{
    *this = other;
}
Ice &Ice::operator=(const Ice & other)
{
    _type = other._type;
    return *this;
}

Ice* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
