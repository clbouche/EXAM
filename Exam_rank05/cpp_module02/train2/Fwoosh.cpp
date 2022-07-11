#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) : ASpell("Fwoosh", "fwooshed")
{}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}


Fwoosh::~Fwoosh()
{}
