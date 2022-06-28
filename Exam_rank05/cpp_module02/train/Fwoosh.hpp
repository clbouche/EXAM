/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:10:07 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:43:27 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
private:

public:
	Fwoosh( void );
	~Fwoosh();

	virtual ASpell *clone() const;

};

