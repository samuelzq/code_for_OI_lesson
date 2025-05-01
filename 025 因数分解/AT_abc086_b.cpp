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

int main()
{
	string a, b;
	int n1, n2;

	cin >> a >> b;
	n1 = stoi(a + b);
	n2 = stoi(b + a);

	if (isPerfectSquare(n1) || isPerfectSquare(n2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}