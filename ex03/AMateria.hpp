#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
    protected:
       std::string _type;

    public:
        virtual ~AMateria();
        AMateria();
        AMateria(const AMateria &other);
        AMateria(std::string const & type);
        AMateria &operator=(const AMateria &other);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif