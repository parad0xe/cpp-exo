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

char* cesar_encode(const char* str, int key) {
    int str_len = strlen(str);
    char* cipher = (char*)malloc(sizeof(char) * (str_len + 1));

    cipher[str_len] = '\0';
    for (int i = 0; i < str_len; i++) {
        cipher[i] = (((str[i] + key) % ((int)'a') % 26) + (int)'a');
    }

    return cipher;
}

char* cesar_decode(const char* str, int key) {
    int str_len = strlen(str);
    char* decipher = (char*)malloc(sizeof(char) * (str_len + 1));

    decipher[str_len] = '\0';
    for (int i = 0; i < str_len; i++)
       decipher[i] = (((int)'z' + 1 + str[i] - key) % ((int)'a') % 26) + (int)'a';

    return decipher;
}

int main() {
    const char* to_encode = "test";

    char* cipher = cesar_encode(to_encode, 2);
    std::cout << "Le mot <" << to_encode << "> est devenu <" << cipher << ">" << std::endl;

    char* decipher = cesar_decode(cipher, 2);
    std::cout << "Le mot <" << cipher << "> est devenu <" << decipher << ">" << std::endl;

    free(cipher);
    free(decipher);

    return 0;
}

