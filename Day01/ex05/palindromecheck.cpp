#include <iostream>
#include <cmath>
#include <cstdlib>

int strlen(const char* str) {
    int i = 0;
    while(*(str + i)) {
        i++;
    }
    return i;
}

bool palindrome_check(const char* str) {
    int start = 0, end = strlen(str) - 1, i = 0;
    while(((start + i) != (end - i)) && (start < end)) {
        if(str[start + i] != str[end - i]) return false;
        i++;
    }
    return true;
}

int main() {

    if(palindrome_check("kayak"))
        std::cout << "Kayak: Palindrome" << std::endl;
    else
        std::cout << "Kayak: Pas palindrome" << std::endl;

    if(palindrome_check("clavier"))
        std::cout << "Clavier: Palindrome" << std::endl;
    else
        std::cout << "Clavier: Pas palindrome" << std::endl;

    return 0;
}

