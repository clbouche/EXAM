#include "Fireball.hpp"

Fireball::Fireball( void ) : ASpell("Fireball", "burnt to a crisp")
{}

ASpell		*Fireball::clone( void ) const 
{
	return (new Fireball());
}


Fireball::~Fireball()
{}