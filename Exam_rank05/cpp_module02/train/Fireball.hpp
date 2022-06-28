#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fireball : public ASpell
{
private:

public:
	Fireball( void );
	~Fireball();

	virtual ASpell *clone() const;

};

