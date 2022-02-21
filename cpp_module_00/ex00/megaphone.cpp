#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (islower(argv[i][j]))
					std::cout << (char)(argv[i][j] - 32);
				else
					std::cout << argv[i][j];
				j++;
			}
			i++;
		}
	}
	return (0);
}
