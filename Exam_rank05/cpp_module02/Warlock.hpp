#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string		_name;
	std::string		_title;

	SpellBook		book;


	Warlock( void );
	Warlock(const Warlock &src);
	Warlock		&operator=(const Warlock &other);
public:
	Warlock(std::string n, std::string t);

	const std::string& getName( void ) const ;
	const std::string& getTitle( void ) const ;

	void			setTitle(std::string t);

	void introduce() const;

	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string spellName);
	void	launchSpell(std::string spellName, ATarget &target);

	~Warlock();
};

#endif


