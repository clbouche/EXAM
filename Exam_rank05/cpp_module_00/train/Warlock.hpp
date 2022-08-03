/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:37:42 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 22:31:31 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Warlock
{
private:
	
	std::string		_name;
	std::string		_title;

	Warlock( void );
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &other);
	
public:

	Warlock(std::string n, std::string t);
	const std::string&		getName( void ) const ;
	const std::string&		getTitle( void ) const ;

	void					setTitle(const std::string &t);

	void					introduce() const;

	~Warlock();
};



