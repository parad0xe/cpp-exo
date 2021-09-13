#include <iostream>
#include <cmath>

int random(int max) {
	 return 1 + rand() % max;
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
		array[i] = random(max_value);

	array[size] = '\0';
}


void order_int(int* array, int array_size, int order = 1) {
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
		order_int(left, left_size, order);

	if(right_size > 1)
		order_int(right, right_size, order);

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

int main() {
	srand((unsigned) time(0));

	int array_size = 20;
	int array[array_size + 1];

	random_array(array, array_size, 1000);
	print_array(array);

	order_int(array, array_size, -1);
	print_array(array);

	return 0;
}
