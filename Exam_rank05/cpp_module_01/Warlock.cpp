
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
	if (spell)
		_storage.insert(std::make_pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}
void	Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator it = _storage.find(spellName);
	if (it != _storage.end())
		delete it->second;
	_storage.erase(spellName);
}
void	Warlock::launchSpell(std::string spellName, ATarget &target)
{
	ASpell *spell = _storage[spellName];
	if (spell)
		spell->launch(target);
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

