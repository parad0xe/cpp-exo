#include <iostream>
#include <cstring> 

int main() {
	int a;
	int b;
	char op;
	std::cout << "Operation: ";
	std::cin >> a >> op >> b;
	
	std::cout << a << " " << op << " " << b << " = ";

	switch(op) {
		case '+':
			std::cout << a + b;
			break;

		case '-':
			std::cout << a - b;
			break;

		case '*':
			std::cout << a * b;
			break;

		case '/':
			std::cout << a / b;
			break;
	}

	std::cout << std::endl;

	return 0;
}
