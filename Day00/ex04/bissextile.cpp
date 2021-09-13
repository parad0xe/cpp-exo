#include <iostream>

int main() {
	int year;

	std::cout << "Quel année ?" << std::endl;
	std::cin >> year;

	if(
		((year % 4 == 0) && (year % 100 != 0)) ||
		((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
	) {
		std::cout << "Année bissextile !" << std::endl;
	} else {
		std::cout << "Année non bissextile !" << std::endl;
	}

	return 0;
}
