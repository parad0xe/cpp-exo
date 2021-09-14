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

void merge_sort(int* array, int array_size, int order = 1) {
	int left_size = (int)std::floor((double)array_size / 2.);
	int right_size = (int)std::ceil((double)array_size / 2.);

	int left[left_size + 1];
	int right[right_size + 1];
	
	int i = 0, i_left = 0, i_right = 0;
	while(i < array_size) {
		if(i % 2 != 0) {
			left[i_left] = array[i];
			i_left++;
		} else {
			right[i_right] = array[i];
			i_right++;
		}
		i++;
	}

	left[left_size] = '\0';
	right[right_size] = '\0';

	if(left_size > 1)
		merge_sort(left, left_size, order);

	if(right_size > 1)
		merge_sort(right, right_size, order);

	int i1 = 0, i_left1 = 0, i_right1 = 0;
	while(i1 < array_size) {
		if(i_left1 == i_left) {
			array[i1] = right[i_right1];
			i_right1++;
		} else if(i_right1 == i_right) {
			array[i1] = left[i_left1];
			i_left1++;
		} else if(
			(left[i_left1] < right[i_right1] && order == 1) || 
			(left[i_left1] > right[i_right1] && order == -1)
		) {
			array[i1] = left[i_left1];
			i_left1++;
		} else {
			array[i1] = right[i_right1];
			i_right1++;
		}

		i1++;
	}
}

void squareup(int* array) {
	for(int i = 0; *(array + i); i++)
		array[i] = pow(array[i], 2);
}

int main() {
	int array_size = 10;
	int array[array_size];

	random_array(array, array_size, 100);
	print_array(array);

	merge_sort(array, array_size);
	print_array(array);

	squareup(array);
	print_array(array);

	return 0;
}
