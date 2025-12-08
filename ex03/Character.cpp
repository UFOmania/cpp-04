#include "Character.hpp"

Character::~Character()
{
    for(int i = 0; i < 4; i++)
        delete _materias[i];
    for(int i = 0; i < 512; i++)
        delete _floor[i];
    
}

Character::Character()
{
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
    for(int i = 0; i < 512; i++)
        _floor[i] = NULL;
    
    _name = "Default";
}
Character::Character(const std::string & name)
{
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
    for(int i = 0; i < 512; i++)
        _floor[i] = NULL;
    _name = name;
}
Character::Character(const Character & other)
{
    *this = other;
}
Character &Character::operator=(const Character & other)
{
    for(int i = 0; i < 4; i++)
    {
        delete _materias[i];
        _materias[i] = other._materias[i]->clone();
    }
    for(int i = 0; i < 4; i++)
    {
        delete _floor[i];
        _floor[i] = other._floor[i]->clone();
    }
    _name = other._name;
    return *this;
}


void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for(int i = 0; i < 4; i++)
    {
        if (_materias[i] == m)
            return;
    }

    for(int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    for(int i = 0; i < 512; i++)
    {
        if(_floor[i] == NULL)
        {
            _floor[i] = _materias[idx];
            _materias[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter & target)
{
    if (_materias[idx])
    {
        _materias[idx]->use(target);
    }
}

std::string const & Character::getName() const
{
    return _name;
}