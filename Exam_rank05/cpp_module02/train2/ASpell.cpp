#include "ASpell.hpp"

ASpell::ASpell( void )
{
}

ASpell::ASpell(const ASpell &src)
{
	*this = src;
}

ASpell	&ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		_name = other._name;
		_effects= other._effects;
	}
	return *this;
}

ASpell::ASpell(std::string n, std::string eff) : _name(n), _effects(eff)
{

}

const std::string&		ASpell::getName( void ) const
{
	return _name;
}
const std::string&		ASpell::getEffects( void ) const
{
	return _effects;
}

void	ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}

ASpell::~ASpell() 
{}