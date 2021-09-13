#include <iostream>

int main() {
	int price = 150000000;
	int income = 31000000;
	int drop_factor = 20;
	int week = 0;

	while(price > 0) {
		price -= income;
		income -= (income * drop_factor) / 100;
		week++;

		if(income < 0.000001) {
			break;
		}
	}

	if(price > 0)
		std::cout << "Le film ne sera pas rentable." << std::endl;
	else
		std::cout << "Rentable dès la semaine " << week << std::endl; 

	return 0;
}
