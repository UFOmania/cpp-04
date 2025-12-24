#include "Character.hpp"
#include "AMateria.hpp"

Character::~Character()
{
	for(int i = 0; i < 4; i++)
        delete _materias[i];

    while (_floor)
	{
		t_node *n = _floor;

		_floor = _floor->next;
		delete n->m;
		delete n;
	}
}

Character::Character()
{
    for(int i = 0; i < 4; i++)
	{
        _materias[i] = NULL;
	}
	_floor = NULL;
    _name = "Default";
}
Character::Character(const std::string & name)
{
    for(int i = 0; i < 4; i++)
	{
        _materias[i] = NULL;
	}
	_floor = NULL;
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
	
	//clear this floor
	if (_floor)
	{
		while (_floor)
		{
			t_node *n = _floor;
			_floor = _floor->next;
			delete n->m;
			delete n;
		}
		_floor = NULL;
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
    if (idx < 0 || idx > 3 || _materias[idx] == NULL)
		{ return ;}

	if (_floor == NULL)
	{
		_floor = new t_node;
		_floor->m = _materias[idx];
	}
	else
	{
		t_node *tmp = _floor;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new t_node;
		tmp->next->m = _materias[idx];
	}
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