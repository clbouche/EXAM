#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
private:
public:
	Dummy( void );
	~Dummy();

	virtual ATarget *clone() const;
};


#endif