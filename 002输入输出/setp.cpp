#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double pi = 3.14159265358979323846;
    cout << setprecision(5) << pi << endl; // 输出5位有效数字
    cout << fixed << setprecision(2) << pi << endl; // 输出2位小数
    return 0;
}