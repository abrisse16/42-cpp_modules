/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:28:13 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/18 18:07:46 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

struct Data
{
    int nbr;
    std::string str;
};

class Serializer
{
    private:

        Serializer();
        Serializer(Serializer const &);
        ~Serializer();
        Serializer & operator=(Serializer const &);
    

    public:
    
        static uintptr_t    serialize(Data *ptr);
        static Data *       deserialize(uintptr_t raw);
};