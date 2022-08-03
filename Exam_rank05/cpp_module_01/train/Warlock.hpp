/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:37:42 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:43:45 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
	
	std::string		_name;
	std::string		_title;

	std::map< std::string, ASpell * > _storage;

	Warlock( void );
	Warlock(const Warlock &src);
	Warlock operator=(const Warlock &other);
	
public:

	Warlock(std::string n, std::string t);
	const std::string&		getName( void ) const ;
	const std::string&		getTitle( void ) const ;

	void					setTitle(const std::string &t);

	void					introduce() const;
	void					learnSpell(ASpell *spell);
	void					forgetSpell(std::string spellName);
	void					launchSpell(std::string spellName, ATarget &target);

	~Warlock();
};



