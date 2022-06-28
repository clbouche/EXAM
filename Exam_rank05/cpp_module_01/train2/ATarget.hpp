/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:46:41 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:29:51 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
private:
	std::string		_type;
public:
	ATarget( void );
	ATarget(std::string t);
	ATarget(const ATarget &src);
	ATarget		&operator=(const ATarget &other);

	const std::string&		getType( void ) const ;
	
	virtual ATarget		*clone() const = 0;

	void	getHitBySpell(const ASpell &spell) const ;

	virtual ~ATarget();
};

#include "ASpell.hpp"

#endif 