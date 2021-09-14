#include <iostream>
#include <cmath>

int random(int min, int max) {
	return floor(rand() % (max - min + 1) + min);
}

void print_array(int* array) {
	std::cout << "array[";

	int i = 0;
	while(*(array + i)) {
		std::cout << *(array + i);
		if(*(array + i + 1)) std::cout << ", ";
		i++;
	}

	std::cout << "]" << std::endl;
}

void random_array(int* array, int size, int max_value) {
	for(int i = 0; i < size; i++)
		array[i] = random(0, max_value);

	array[size] = '\0';
}

int array_search(int* array, int value) {
	for(int i = 0; *(array + i); i++)
	{
		if(array[i] == value)
			return i;
	}
	return -1;
}

int main() {
	srand((unsigned) time(0));
	
	int array_size = 10;
	int array[array_size];

	random_array(array, array_size, 1000);
	print_array(array);

	std::cout << "search => " << array_search(array, array[4]) << std::endl;

	return 0;
}
