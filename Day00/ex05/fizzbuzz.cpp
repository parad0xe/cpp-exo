#include <iostream>

std::string fizzbuzz(int n) {
	if(n % 3 == 0 && n % 5 == 0) {
		return "fizzbuzz";
	} else if(n % 3 == 0) {
		return "fizz";
	}

	return "buzz";
}

int main() {
	std::cout << fizzbuzz(3) << std::endl;
	std::cout << fizzbuzz(5) << std::endl;
	std::cout << fizzbuzz(15) << std::endl;
	return 0;
}
