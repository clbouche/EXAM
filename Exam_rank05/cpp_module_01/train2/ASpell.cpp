/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:43:56 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:29:08 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell( void )
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
	return *this;
}

const std::string&		ASpell::getName( void ) const 
{
	return _name;
}

const std::string&		ASpell::getEffects( void ) const 
{
	return _effects;
}

void					ASpell::launchFunction(const ATarget &target) const 
{
	target.getHitBySpell(*this);
}


ASpell::~ASpell()
{
}