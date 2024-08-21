#ifndef WEAPON_HPP
# define WEAPON_HPP


#include <iostream>
#include <string>

class Weapon {
    private :
        std::string type;
    public :
        Weapon(std::string type);
        const std::string &gettype();
        void setType(std::string type);

};

#endif