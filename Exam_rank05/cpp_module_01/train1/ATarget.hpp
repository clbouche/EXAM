#include <string>
#include <iostream>
#include "Aspell.hpp"

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

	virtual ATarget		*clone( void ) const = 0;

	void		getHitBySpell( const Aspell& spell ) const ;

	virtual ~ATarget();
};