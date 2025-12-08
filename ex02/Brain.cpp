#include "Brain.hpp"

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
    *this = other;
    std::cout << "Brain's Copy has been Created" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    for(int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    return *this;
}













