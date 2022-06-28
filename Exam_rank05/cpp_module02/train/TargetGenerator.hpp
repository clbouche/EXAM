/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:18:17 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 21:35:43 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:

	std::map<std::string, ATarget *> _targetStorage;

	TargetGenerator(const TargetGenerator &src);
	TargetGenerator	&operator=(const TargetGenerator &other);
	
public:
	TargetGenerator(void);

	void		learnTargetType(ATarget *target);
	void		forgetTargetType(std::string const &targetType);
	ATarget		*createTarget(std::string const &targetType);

	~TargetGenerator();
};


