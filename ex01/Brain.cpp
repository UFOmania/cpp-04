#include "Brain.hpp"
#include <iostream>

Brain::~Brain()
{
    std::cout << "Brain has been Destroyed" << std::endl;
}

Brain::Brain()
{
    std::cout << "Brain has been Created" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain's Copy has been Created" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}













