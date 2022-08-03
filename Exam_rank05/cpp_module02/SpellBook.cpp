#include "SpellBook.hpp"

SpellBook::SpellBook( void )
{
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
			_storage.insert(std::make_pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _storage.find(spellName);
	if (it != _storage.end())
		delete it->second;
	_storage.erase(spellName);
}

ASpell	*SpellBook::createSpell(std::string const &spellName)
{
    std::map<std::string, ASpell *>::iterator it = _storage.find(spellName);
    if (it != _storage.end())
        return _storage[spellName];
    return NULL;
}


SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = this->_storage.begin();
    std::map<std::string, ASpell *>::iterator ite = this->_storage.end();
    while (it != ite)
    {
        delete it->second;
        ++it;
    }
    this->_storage.clear();
}