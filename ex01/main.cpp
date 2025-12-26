#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// void foo()
// {
//     system("leaks Animal");
// }

int main()
{
    // atexit(foo);
    Animal *animals[10];
    for(int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for(int i = 0; i < 10; i++)
	{

		delete animals[i];
	}


	Cat c;
	std::cout << std::endl;
	Cat b;
	std::cout << std::endl;
	b = c;
	std::cout << std::endl;
	// {
	// 	Cat c;
	// 	b = c;
	// }
	

	return 0;
}