#include <iostream>
#include <cmath>
#include <cstdlib>

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

void debug(const char* title, int a) {
	std::cout << title << " " << a << std::endl;
}

void nl() {
	std::cout << std::endl;
}

int* sort_3(int* array) {
    int* new_array = (int*)calloc(4, sizeof(int));
    new_array[4] = '\0';

    for (int i = 0; *(array + i); i++) {
        for (int j = 2; j >= 0; j--) {
            if(array[i] > new_array[j]) {
                if(j > 1) new_array[j - 2] = new_array[j - 1];
                if(j > 0) new_array[j - 1] = new_array[j];

                new_array[j] = array[i];
                break;
            }
        }
    }

    return new_array;
}

int main() {
	srand((unsigned) time(0));

	int array_size = 10;
	int array[array_size];

	random_array(array, array_size, 100);
	print_array(array);

	int* sorted_array = sort_3(array);
    print_array(sorted_array);
	free(sorted_array);

	return 0;
}
