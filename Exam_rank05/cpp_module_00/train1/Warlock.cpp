#include "Warlock.hpp"

Warlock::Warlock(std::string n, std::string t) : _name(n), _title(t)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string		Warlock::getName( void ) const
{
	return _name;
}

std::string		Warlock::getTitle( void ) const 
{
	return _title;
}

void			Warlock::setTitle(const std::string &t)
{
	_title = t;
}

void			Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}