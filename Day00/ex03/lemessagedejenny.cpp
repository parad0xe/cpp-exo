#include <iostream>

int main() {
	std::string name;

	std::cout << "Bonjour quel est ton prènom ?" << std::endl;
	std::cin >> name;

	if(name.compare("Johnny") == 0)
		std::cout << "Hello, my love!" << std::endl;
	else
		std::cout << "Salut, " << name << "!" << std::endl;

	return 0;
}
