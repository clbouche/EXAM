/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:10:33 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:36:54 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) : ASpell("Fwoosh", "fwooshed")
{}

ASpell		*Fwoosh::clone( void ) const 
{
	return (new Fwoosh());
}


Fwoosh::~Fwoosh()
{
}