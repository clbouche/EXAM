#include <string>
#include <iostream>
// #include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
	std::string		_name;
	std::string		_effects;
public:
	ASpell( void );
	ASpell(std::string n, std::string eff);
	ASpell(const ASpell &src);
	ASpell		&operator=(const ASpell &other);

	std::string		getName( void ) const;
	std::string		getEffects( void ) const ;

	virtual ASpell		*clone( void ) const = 0 ;

	void		launch(const ATarget &target);

	virtual ~ASpell();
};

