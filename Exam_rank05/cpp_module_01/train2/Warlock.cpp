/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:33:59 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:33:13 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string n, const std::string t) : _name(n), _title(t)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}


const std::string&		Warlock::getName( void ) const 
{
	return _name;
}

const std::string&		Warlock::getTitle( void ) const
{
	return _title;
}

void					Warlock::setTitle(const std::string &t)
{
	_title = t;
}

void					Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void					Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spellStorage.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void					Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator		it = _spellStorage.find(spellName);
	if (it != _spellStorage.end())
		delete it->second;
	_spellStorage.erase(spellName);
}

void					Warlock::launchSpell(std::string spellName, const ATarget &target)
{
	ASpell *spell = _spellStorage[spellName];
	if (spell)
		spell->launchFunction(target);
}


Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator 	it = _spellStorage.begin();
	std::map<std::string, ASpell *>::iterator	ite = _spellStorage.end();

	while (it != ite)
	{
		delete it->second;
		++it;
	}
	_spellStorage.clear();
}