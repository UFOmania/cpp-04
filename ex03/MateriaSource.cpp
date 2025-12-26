#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        delete _materias[i];
}
MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource & other)
{
    for(int i = 0; i < 4; i++)
        _materias[i] = NULL;
    *this = other;
}
MateriaSource &MateriaSource::operator=(const MateriaSource & other)
{
    if (this == &other)
        return *this;
    for(int i = 0; i < 4; i++)
    {
        delete _materias[i];
        _materias[i] = NULL;
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return ;
    for(int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
    for(int i = 3; i >= 0; i--)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return _materias[i]->clone();
        }
    }
    return 0;
}