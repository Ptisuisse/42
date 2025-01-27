#include "FragTrap.hpp"

void    FragTrap::highFivesGuys(void)
{
    if (getHealthPoints() == 0)
    {
        std::cout << "Sorry to tell you but ..." << name << " is dead" << std::endl;
        return ;
    }
    std::cout << "FragTrap is asking for a high five!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    if (name == "")
    {
        this->name = "FragTrap";
        return ;
    }
    std::cout << name << " is ready to fight!" << std::endl;
}

FragTrap::FragTrap()
{
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap" << std::endl;
}