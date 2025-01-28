#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap & operator=(FragTrap const & src);
		FragTrap(std::string name);
		~FragTrap();
		void highFivesGuys(void);
    private:
};

#endif