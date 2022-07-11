#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget("Target Practice Dummy")
{}

Dummy::~Dummy()
{}

ATarget *Dummy::clone() const
{
	return (new Dummy());	
}