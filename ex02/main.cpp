#include "Dog.hpp"
#include "Cat.hpp"

void foo()
{
    system("leaks Animal");
}

int main()
{
    atexit(foo);
    Animal *animals[10];
    for(int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for(int i = 0; i < 10; i++)
        delete animals[i];

    // Animal *a = new Dog();
    // Animal c(*a);

    // delete a;
    return 0;
}