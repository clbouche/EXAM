/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:49:22 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:31:29 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget( void )
{}

ATarget::ATarget(std::string t) : _type(t)
{}

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget		&ATarget::operator=(const ATarget &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

const std::string&		ATarget::getType( void ) const
{
	return _type;
}

void	ATarget::getHitBySpell(const ASpell &spell) const 
{
	std::cout << _type << " has been " << spell.getEffects() << std::endl;
}

ATarget::~ATarget()
{}
