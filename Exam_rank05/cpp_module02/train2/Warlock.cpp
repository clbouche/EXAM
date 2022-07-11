
#include "Warlock.hpp"

Warlock::Warlock(std::string n, std::string t) : _name(n), _title(t)
{
	std::cout << _name << " This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName( void ) const
{
	return _name;
}

const std::string& Warlock::getTitle( void ) const
{
	return _title;
}

void			Warlock::setTitle(std::string t)
{
	_title = t;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	book.learnSpell(spell);
}
void	Warlock::forgetSpell(std::string spellName)
{
	book.forgetSpell(spellName);
}
void	Warlock::launchSpell(std::string spellName, ATarget &target)
{
 	ATarget const *test = 0;
    if (test == &target)
        return;
    ASpell *temp = book.createSpell(spellName);
    if (temp)
        temp->launch(target);
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

