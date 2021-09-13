#include <iostream>

int main() {
	int n;

	std::cout << "Entrer un nombre: ";
	std::cin >> n;

	for(int i = 1; i <= 10; i++)
		std::cout << n << " * " << i << " = " << (n * i) << std::endl;

	return 0;
}
