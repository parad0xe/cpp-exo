#include <iostream>
#include <string>
#include <cmath>

void is_amstrong_number(int n) {
	int digital_number = floor(log10(abs(n))) + 1;
	std::string str_number = std::to_string(n);

	int value = 0;
	for(int i = 0; i < digital_number; i++) {
		value += pow((int)((int)str_number[i] - '0'), digital_number);
	}

	if(value == n)
		std::cout << n << " est un nombre d'Armstrong";
	else
		std::cout << n << " n'est pas un nombre d'Armstrong";

	std::cout << std::endl;
}

int main() {
	int number;
	std::cout << "Entrer un nombre : ";
	std::cin >> number;

	is_amstrong_number(number);
	return 0;
}
