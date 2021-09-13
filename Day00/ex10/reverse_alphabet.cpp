#include <iostream>

void displayAscii(int start, int end) {
	if(start < end) {
		for(int i = start; i <= end; i++)
			std::cout << (char)i;
	} else {
		for(int i = start; i >= end; i--)
		std::cout << (char)i;
	}

	std::cout << std::endl;
}

int main() {
	displayAscii((int)'z', (int)'a');
	displayAscii((int)'Z', (int)'A');

	return 0;
}
