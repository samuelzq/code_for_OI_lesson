#include <iostream>
using namespace std;

// 使用 #define 定义 PI
#define PI 3.14159

int main() {
    // 使用 PI 计算圆的面积（假设半径为 5
    double radius = 5.0;
    double area = PI * radius * radius;

    // 输出圆的面积
    cout << "The area of the circle with radius " << radius << " is: " << area << endl;

    // 注意：由于 PI 是通过 #define 定义的，所以它是一个简单的文本替换，
    // 而不是一个变量。这意味着在编译时，所有 PI 的出现都会被替换为 3.14159。

    return 0;
}
