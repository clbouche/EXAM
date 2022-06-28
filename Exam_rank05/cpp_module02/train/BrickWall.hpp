
#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
private:

public:
	BrickWall( void );	
	~BrickWall();

	virtual ATarget *clone() const;

};


