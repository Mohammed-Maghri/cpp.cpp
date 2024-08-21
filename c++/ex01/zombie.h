#ifndef ZOMBIE_H
# define ZOMBIE_H


#include <string>
#include <iostream>

class Zombie {
    private : 
        std::string name ;
    public :
        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );


#endif