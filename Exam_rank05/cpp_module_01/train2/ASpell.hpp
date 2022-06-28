/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:40:09 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:28:07 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

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
		const std::string&		getEffects( void ) const ;

		void	launchFunction(const ATarget &target) const ;

		virtual ASpell		*clone() const = 0;

		virtual ~ASpell();
};

#include "ATarget.hpp"

#endif