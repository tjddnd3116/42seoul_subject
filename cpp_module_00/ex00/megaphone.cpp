#include <iostream>

class awake {
	public:
		awake() {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		}
		awake(int argc, char **argv) {
			int i;

			i = 1;
			if (argc == 1)
				std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			else {
				while (i < argc) {
					std::cout << argv[i];
					i++;
				}
				std::cout << std::endl;
			}
		}
};

int main(int argc, char **argv)
{
	awake megaphone(argc, argv);
	return (0);
}
