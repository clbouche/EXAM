/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:04:54 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 22:29:29 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook( void )
{
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		_spellStorage.insert(std::make_pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _spellStorage.find(spellName);
	if (it != _spellStorage.end())
		delete it->second;
	_spellStorage.erase(spellName);
}

ASpell	*SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _spellStorage.find(spellName);
    if (it != _spellStorage.end())
        return _spellStorage[spellName];
    return NULL;
}

SpellBook::~SpellBook()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->_spellStorage.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->_spellStorage.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->_spellStorage.clear();
}