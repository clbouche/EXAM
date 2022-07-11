#include "Polymorph.hpp"

Polymorph::Polymorph( void ) : ASpell("Polymorph", "turned into a critter")
{}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}


Polymorph::~Polymorph()
{}
