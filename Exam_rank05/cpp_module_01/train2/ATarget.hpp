#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
	std::string		_type;
public:
	ATarget( void );
	ATarget(std::string t);
	ATarget(const ATarget &src);
	ATarget		&operator=(const ATarget &other);

	const std::string&	getType( void ) const ;

	virtual ATarget *clone() const = 0 ;

	void		getHitBySpell(ASpell const &spell) const;

	virtual ~ATarget();
};

#endif

