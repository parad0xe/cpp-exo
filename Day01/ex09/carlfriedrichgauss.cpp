#include <iostream>

int gauss_sum(int min, int max) {
    if(min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }

    min--;

    return ((max * (max + 1)) / 2) - ((min * (min + 1)) / 2);
}
int main() {
    std::cout << "GaussSum(1, 100) = " << gauss_sum(1, 100) << std::endl;
    std::cout << "GaussSum(2, 100) = " << gauss_sum(2, 100) << std::endl;
    std::cout << "GaussSum(3, 90) = " << gauss_sum(3, 90) << std::endl;
    return 0;
}

