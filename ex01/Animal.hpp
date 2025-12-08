#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"


class Animal
{
    protected:
        std::string type;

    
    public:
        virtual ~Animal();
        Animal();
        Animal(const Animal &other);
        Animal(const std::string &type);
        Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        std::string getType() const;
    
};

#endif