#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num = 255;
    cout << uppercase << hex << num << endl; // 输出十六进制
    cout << oct << num << endl; // 输出八进制
    return 0;
}