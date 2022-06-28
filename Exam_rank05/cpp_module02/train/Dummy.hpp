/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:13:59 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:43:31 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget
{
private:

public:
	Dummy( void );	
	~Dummy();

	virtual ATarget *clone() const;

};


