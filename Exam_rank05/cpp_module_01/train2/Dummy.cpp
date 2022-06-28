/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:58:14 by clbouche          #+#    #+#             */
/*   Updated: 2022/06/28 09:16:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget("Target Practice Dummy")
{
}

ATarget		*Dummy::clone() const
{
	return (new Dummy());
}

Dummy::~Dummy()
{
}
