#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string str = "hello1world";
    for (char& c : str) {
        c = std::toupper(c);
    }
    std::cout << str << std::endl;
    return 0;
}
