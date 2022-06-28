/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:02:35 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 21:31:14 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:

	std::map<std::string, ASpell *> _spellStorage;

	SpellBook(const SpellBook &src);
	SpellBook	&operator=(const SpellBook &other);
public:
	SpellBook( void );

	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string const &spellName);
	ASpell	*createSpell(std::string const &spellName);
	
	~SpellBook();
};

