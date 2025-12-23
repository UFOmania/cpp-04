#include "WrongCat.hpp"
#include <iostream>

WrongCat::~WrongCat()
{
    std::cout << "WrongCat got Destroyed" << std::endl;
}
WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "Default WrongCat is Constrtucted" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Copy WrongCat is Constrtucted" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return *this;
    WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "meoing !!!" << std::endl;
}