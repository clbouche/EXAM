/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:42:37 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 17:47:24 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string n, std::string t) : _name(n), _title(t)
{
	std::cout << _name << ": This looks like another borind day." << std::endl;
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


Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}