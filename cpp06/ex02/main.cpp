/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:03:00 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/18 19:18:58 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int i = rand() % 3;
    if (i == 0)
    {
        std::cout << "generated: A" << std::endl;
        return new A;
    }
    else if (i == 1)
    {
        std::cout << "generated: B" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "generated: C" << std::endl;
        return new C;
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "identified: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "identified: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "identified: C" << std::endl;
    else
        std::cout << "not identified" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "identified: A" << std::endl;
        (void)a;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "identified: B" << std::endl;
            (void)b;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "identified: C" << std::endl;
                (void)c;
            }
            catch(const std::exception& e)
            {
                std::cout << "not identified" << std::endl;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}