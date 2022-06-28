/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:20:39 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 22:28:01 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{}


void		TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		_targetStorage.insert(std::make_pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void		TargetGenerator::forgetTargetType(std::string const &targetType)
{
	std::map<std::string, ATarget *>::iterator it = _targetStorage.find(targetType);
	if (it != _targetStorage.end())
		delete it->second;
	_targetStorage.erase(targetType);
}

ATarget		*TargetGenerator::createTarget(std::string const &targetType)
{
    std::map<std::string, ATarget *>::iterator it = _targetStorage.find(targetType);
    if (it != _targetStorage.end())
        return _targetStorage[targetType];
    return NULL;
}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->_targetStorage.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->_targetStorage.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->_targetStorage.clear();
}