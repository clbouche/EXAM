#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class SpellBook
{
private:
	SpellBook(const SpellBook &src);
	SpellBook	&operator=(const SpellBook &other);

	std::map<std::string, ASpell *>		_storage;

public:
	SpellBook( void );

	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string const &spellName);
	ASpell	*createSpell(std::string const &spellName);

	~SpellBook();
};




#endif