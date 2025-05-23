#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string input = argv[1];
	int levelIndex = -1;

	for (int i = 0; i < 4; ++i) {
		if (input == levels[i]) {
			levelIndex = i;
			break;
		}
	}

	Harl harl;

	switch (levelIndex) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}
