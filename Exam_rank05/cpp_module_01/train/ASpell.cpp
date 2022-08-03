/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:54:16 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:55:09 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell( void ) : _name("Spell"), _effects("effects")
{}


ASpell::ASpell(std::string n, std::string eff) : _name(n), _effects(eff)
{
	
}

ASpell::ASpell(const ASpell &src)
{
	*this = src;
}

ASpell		&ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		_name = other._name;
		_effects = other._effects;
	}
	return (*this);
}
const std::string&		ASpell::getName( void ) const
{
	return _name;
}

const std::string&		ASpell::getEffects( void ) const
{
	return _effects;
}

void					ASpell::launchFunction(ATarget const &target) const
{
	target.getHitBySpell(*this);
}

ASpell::~ASpell()
{}