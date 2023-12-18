/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:00:34 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/18 18:08:46 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main()
{
    Data data;
    data.nbr = 42;
    data.str = "Hello World !";

    uintptr_t raw = Serializer::serialize(&data);
    Data *dataPtr = Serializer::deserialize(raw);

    if (&data == dataPtr)
        std::cout << "Data and dataPtr are the same" << std::endl;
    else
        std::cout << "Data and dataPtr are different" << std::endl;

    return 0;
}