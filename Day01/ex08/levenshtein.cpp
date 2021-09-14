#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

int strlen(const char *str) {
    int i = 0;
    while (*(str + i)) {
        i++;
    }
    return i;
}

void print_vector2D(std::vector <std::vector<int>> array, int rows, int cols) {
    std::cout << "vector2D[" << std::endl;
    for (int i = 0; i < rows; i++) {
        std::cout << "    [";
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j];
            if (j < cols - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < rows - 1) std::cout << "," << std::endl;
    }
    std::cout << std::endl << "]" << std::endl;
}

int levenshtein(std::string str1, std::string str2) {
    int len_a = str1.size() + 1;
    int len_b = str2.size() + 1;

    std::vector <std::vector<int>> vec;
    vec.resize(len_a, std::vector<int>(len_b, 0));

    for (int i = 1; i < len_a; i++)
        vec[i][0] = i;

    for (int j = 1; j < len_b; j++)
        vec[0][j] = j;

    for (int i = 1; i < len_a; i++) {
        for (int j = 1; j < len_b; j++) {
            const int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            vec[i][j] = std::min(
                    std::min(
                            vec[i - 1][j] + 1,
                            vec[i][j - 1] + 1
                    ),
                    vec[i - 1][j - 1] + cost
            );
        }
    }

    print_vector2D(vec, len_a, len_b);

    return vec[len_a - 1][len_b - 1];
}

int main() {
    std::string str1 = "examen";
    std::string str2 = "examan";
    int d = levenshtein(str1, str2);
    std::cout << "levenshtein(" << str1 << ", " << str2 << ") = " << d << std::endl;

    std::cout << std::endl;

    str1 = "niche";
    str2 = "chien";
    d = levenshtein(str1, str2);
    std::cout << "levenshtein(" << str1 << ", " << str2 << ") = " << d << std::endl;

    return 0;
}

