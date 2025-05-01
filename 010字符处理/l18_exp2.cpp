#include <bits/stdc++h.h>

int main() {
    std::string str = "HELLO WORLD";
    for (char& c : str) {   // for (int i = 0; i < str.length(); i++) {str[i]
        c = std::tolower(c);  // c - 'A' + 'a'
    }
    std::cout << str << std::endl;
    return 0;
}
