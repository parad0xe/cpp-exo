#include <iostream>

void displayAscii(int start, int end) {
	for(int i = start; i <= end; i++)
		std::cout << (char)i;
	std::cout << std::endl;
}
int main() {
	displayAscii((int)'a', (int)'z');
	displayAscii((int)'A', (int)'Z');

	return 0;
}
