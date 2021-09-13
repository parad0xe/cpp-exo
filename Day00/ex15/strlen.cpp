#include <iostream>

int strlen(const char* str) {
	int i = 0;
	while(*(str + i)) {
		i++;
	}

	return i;
}

int main() {
	
	std::cout << "Length: " << strlen("une chaine de caractère") << std::endl;

	return 0;
}
