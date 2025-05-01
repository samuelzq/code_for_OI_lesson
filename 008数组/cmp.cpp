#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str1[] = "apple";
    char str2[] = "banana";
    int result;

    // 比较 str1 和 str2
    result = strcmp(str1, str2);
    if (result < 0) {
        cout << str1 << " is less than " << str2 << endl;
    } else if (result > 0) {
        cout << str1 << " is greater than " << str2 << endl;
    } else {
        cout << str1 << " is equal than " << str2 << endl;
    }

    return 0;
}