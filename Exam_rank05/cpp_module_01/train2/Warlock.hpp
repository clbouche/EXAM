/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:29:30 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:27:05 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
// class ASPell;

class Warlock
{
	private:
		std::string		_name;
		std::string		_title;

		std::map<std::string, ASpell *>		_spellStorage;

		Warlock( void );
		Warlock(const Warlock &src);
		Warlock &operator=(const Warlock &other);


	public:
		Warlock(const std::string n, const std::string t);
		~Warlock();

		const std::string&		getName( void ) const ;
		const std::string&		getTitle( void ) const ;
		
		void					setTitle(const std::string &t);

		void					introduce() const;

		void					learnSpell(ASpell *spell);
		void					forgetSpell(std::string spellName);
		void					launchSpell(std::string spellName, const ATarget &target);

};


#endif