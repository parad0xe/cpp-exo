#include <iostream>

void displayKm(double miles) {
	double km = miles * 1.60934;
	std::cout << miles << " miles -> " << km << " km" << std::endl;
}

int main() {
	
	double miles;

	std::cout << "Enter le nombre de miles: ";
	std::cin >> miles;

	displayKm(miles);

	return 0;
}
