/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:59:05 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:56:42 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
protected:
	std::string		_type;
public:
	ATarget( void );
	ATarget( std::string t);
	ATarget( const ATarget &src);
	ATarget		&operator=(const ATarget &other);

	const std::string& 	getType( void ) const ;

	virtual ATarget		*clone( void ) const = 0 ;

	void		getHitBySpell(ASpell const &spell) const ;
 
	virtual ~ATarget();
};

#include "ASpell.hpp"

