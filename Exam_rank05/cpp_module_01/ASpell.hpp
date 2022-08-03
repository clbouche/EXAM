#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string		_name;
	std::string		_effects;
public:
	ASpell( void );
	ASpell(const ASpell &src);
	ASpell	&operator=(const ASpell &other);
	ASpell(std::string n, std::string eff);

	const std::string&		getName( void ) const;
	const std::string&		getEffects( void ) const;

	void	launch(const ATarget &target) const ;

	virtual ASpell* clone() const = 0;

	virtual ~ASpell();
};

#endif

