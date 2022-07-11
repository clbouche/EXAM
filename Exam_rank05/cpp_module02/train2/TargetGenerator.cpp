#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator( void )
{
}


void	TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		_storage.insert(std::make_pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &targetType)
{
	std::map<std::string, ATarget *>::iterator it = _storage.find(targetType);
	if (it != _storage.end())
		delete it->second;
	_storage.erase(targetType);
}

ATarget	*TargetGenerator::createTarget(std::string const &targetType)
{
	std::map<std::string, ATarget *>::iterator it = _storage.find(targetType);
    if (it != _storage.end())
        return _storage[targetType];
    return NULL;
}


TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = this->_storage.begin();
    std::map<std::string, ATarget *>::iterator ite = this->_storage.end();
    while (it != ite)
    {
        delete it->second;
        ++it;
    }
    this->_storage.clear();
}