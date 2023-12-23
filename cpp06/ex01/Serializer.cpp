/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:58:06 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/23 13:30:30 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <stdint.h>

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const & src)
{
    *this = src;
}

Serializer::~Serializer()
{
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

uintptr_t    Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *       Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}