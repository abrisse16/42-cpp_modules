#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str = av[i];
			std::string::iterator it;
			for (it = str.begin(); it != str.end(); it++)
				std::cout << (char)toupper(*it);
		}
		std::cout << std::endl;
	}
	return 0;
}