#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <string>
#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
private:

	std::map<std::string, ATarget *>	_storage;

	TargetGenerator(const TargetGenerator &src);
	TargetGenerator 	&operator=(const TargetGenerator &other);
public:
	TargetGenerator( void );

	void	learnTargetType(ATarget *target);
	void	forgetTargetType(std::string const &targetType);
	ATarget	*createTarget(std::string const &targetType);

	~TargetGenerator();
};

#endif