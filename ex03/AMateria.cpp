#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::~AMateria(){}
AMateria::AMateria(){}
AMateria::AMateria(const std::string & type) : _type(type){}
AMateria::AMateria(const AMateria & other){*this = other; }
AMateria & AMateria::operator=(const AMateria & other)
{
    _type = other._type;
    return *this;
}

const std::string &AMateria::getType() const
{
    return _type;
}

AMateria* AMateria::clone() const
{
	return NULL;
}
void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << "\n";
}






