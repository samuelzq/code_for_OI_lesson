#include <iostream>
using namespace std;

int main() { 
    int x = 5;
    int y = 10;

    if (x > 10 && y < 5) {
        cout << "Both conditions are true." << endl;
    } else {
        cout << "At least one condition is false." << endl;
    } // 输出 "At least one condition is false."，因为 x > 10 为 false，不会评估 y < 5

    if (x < 10 || y > 20) {
        cout << "At least one condition is true." << endl;
    } else {
        cout << "Both conditions are false." << endl;
    } // 输出 "At least one condition is true."，因为 x < 10 为 true，不会评估 y > 20

    return 0;
}