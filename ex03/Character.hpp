#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria    *_materias[4];
        std::string _name;
        AMateria    *_floor[512];

    public:
        ~Character();
        Character();
        Character(const Character &other);
        Character(const std::string &name);
        Character &operator=(const Character &other);
        
        std::string const & getName() const;
        void equip(AMateria* m); //maybe uniqe
        void unequip(int idx);
        void use(int idx, ICharacter& target);


};      


#endif