#include "Character.hpp"
#include "AMateria.hpp"

Character::~Character()
{
    for(int i = 0; i < 4; i++)
        delete _materias[i];
    for(std::vector<AMateria *>::iterator it = _floor.begin(); it != _floor.end(); ++it)
		delete *it;
    
}

Character::Character()
{
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
    _name = "Default";
}
Character::Character(const std::string & name)
{
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
    _name = name;
}
Character::Character(const Character & other)
{
    *this = other;
}
Character &Character::operator=(const Character & other)
{
	if (this == &other)
		return *this;

    for(int i = 0; i < 4; i++)
    {
        delete _materias[i];
        _materias[i] = other._materias[i]->clone();
    }

	//clear the old floor
    for(std::vector<AMateria *>::iterator it = _floor.begin(); it != _floor.end(); ++it)
    	{ delete *it; }
	_floor.clear();

	//set a new one
	for(std::vector<AMateria*>::const_iterator it = other._floor.begin(); it != other._floor.end(); ++it)
    { _floor.push_back((*it)->clone()); }

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
    if (idx < 0 || idx > 3 || _materias[idx] == NULL)
		{ return ;}

	_floor.push_back(_materias[idx]);
	_materias[idx] = NULL;

}

void Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx > 3 || _materias[idx] == NULL)
       { return ;}
    
    _materias[idx]->use(target);
    
}

std::string const & Character::getName() const
{
    return _name;
}