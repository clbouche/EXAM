/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:14:52 by claclou           #+#    #+#             */
/*   Updated: 2022/06/27 18:35:48 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget("Target Practice Dummy")
{}

ATarget		*Dummy::clone( void ) const
{
	return (new Dummy());
}

Dummy::~Dummy()
{}
