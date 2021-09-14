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

bool in_string(const char* str, int slen, int index, int offset = 0) {
    for (int i = offset; i < slen; i++)
        if(str[i] == str[index] && index != i) return true;
    return false;
}

int first_unique_char_of(const char* str) {
    int len = strlen(str);
    bool has_repeat = false;

    for (int i = 0; i < len; ++i) {
        if(!has_repeat) {
            if(in_string(str, len, i)) {
                has_repeat = true;
                continue;
            }
        } else {
            if(!in_string(str, len, i))
                return i;
        }
    }

    return (has_repeat) ? -2 : -1;
}

int main() {

    int index = first_unique_char_of("test");
    if(index == -1)
        std::cout << "Aucun caractère répété pour <test>" << std::endl;
    else if(index == -2)
        std::cout << "Tout les caractères sont répété au moins une fois pour <test>" << std::endl;
    else
        std::cout << "Le premier caractère non répété pour <test> est à la position " << index << std::endl;

    index = first_unique_char_of("abc");
    if(index == -1)
        std::cout << "Aucun caractère répété pour <abc>" << std::endl;
    else if(index == -2)
        std::cout << "Tout les caractères sont répété au moins une fois pour <abc>" << std::endl;
    else
        std::cout << "Le premier caractère non répété pour <abc> est à la position " << index << std::endl;

    index = first_unique_char_of("aabbcc");
    if(index == -1)
        std::cout << "Aucun caractère répété pour <aabbcc>" << std::endl;
    else if(index == -2)
        std::cout << "Tout les caractères sont répété au moins une fois pour <aabbcc>" << std::endl;
    else
        std::cout << "Le premier caractère non répété pour <aabbcc> est à la position " << index << std::endl;

    return 0;
}

