#include "Cure.hpp"


Cure::~Cure()
{}

Cure::Cure()
{
    _type = "cure";
}
Cure::Cure(const Cure & other) : AMateria("cure")
{
    *this = other;
}
Cure &Cure::operator=(const Cure & other)
{
    _type = other._type;
    return *this;
}

AMateria* Cure::clone() const 
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
