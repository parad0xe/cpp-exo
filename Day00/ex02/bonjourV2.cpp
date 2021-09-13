#include <iostream>

int main() {
	char name[20];

	std::cout << "Bonjour ! Quel est votre prénom ?" << std::endl;
	std::cin >> name;

	std::cout << name << " enchanté moi c'est James, James Bond." << std::endl;

	return 0;
}
