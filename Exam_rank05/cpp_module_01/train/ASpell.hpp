/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:50:35 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:56:56 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
protected:
	std::string		_name;
	std::string		_effects;
public:
	ASpell( void );
	ASpell(std::string n, std::string eff);
	ASpell(const ASpell &src);
	ASpell		&operator=(const ASpell &other);

	const std::string&		getName( void ) const ;
	const std::string&		getEffects( void ) const;
	
	void					launchFunction(const ATarget &target) const ;

	virtual ASpell		*clone( void ) const = 0 ;
	
	virtual ~ASpell();
};

#include "ATarget.hpp"

