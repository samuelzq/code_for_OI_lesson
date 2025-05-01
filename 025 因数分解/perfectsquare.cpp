#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int num) {
    // 检查num是否小于0，因为负数没有实数平方根
    if (num < 0) return false;

    // 使用sqrt函数计算平方根，并检查是否为整数
    // 注意：由于sqrt返回double类型，代码中隐含着类型转换
    int root = sqrt(num);
    return root * root == num;
}

int main() {
    int number;
    cout << "请输入一个整数: ";
    cin >> number;

    if (isPerfectSquare(number))
        cout << number << " 是完全平方数。" << endl;
    else
        cout << number << " 不是完全平方数。" << endl;

    return 0;
}
