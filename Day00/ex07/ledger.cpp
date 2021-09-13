#include <iostream>

int getPrice(const char* money_name) {
	int price;
	std::cout << "Prix de " << money_name << ": ";
	std::cin >> price;
	return price;
}

int main() {
	double bitcoins = 7.2;
	double ethereums = 180.5;
	double xrp = 4500.;
	double dodge = 17890.78;
	double cardano = 5783.32;

	double b_price = getPrice("Bitcoin");
	double e_price = getPrice("Etheureum");
	double x_price = getPrice("XRP");
	double d_price = getPrice("Dodge");
	double c_price = getPrice("Cardano");

	double total = (bitcoins * b_price) + 
		(ethereums * e_price) +
		(xrp * x_price) +
		(dodge * d_price) + 
		(cardano * c_price);

	std::cout << "Total: " << total << std::endl;

	return 0;
}
