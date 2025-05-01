#include <iostream>

using namespace std;

int main() {
    int x = 5;

    if (x > 0) {
        cout << "x 是正数" << endl;
    } else if (x < 0) {
        cout << "x 是负数" << endl;
    } else {
        cout << "x 是零" << endl;
    }

    return 0;
}