#include <iostream>
using namespace std;

// 使用 #define 定义 MAX 宏
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 10;
    int y = 20;

    // 使用 MAX 宏获取两个数中的较大值
    int max_value = MAX(x, y);

    // 输出结果
    cout << "The maximum value between " << x << " and " << y << " is: " << max_value << endl;

    // 注意：当使用表达式作为参数时，务必小心运算符优先级和副作用
    int i = 5;
    int j = 10;
    int max_inc = MAX(i++, j++); // 通常不推荐这样做，因为i和j都可能被递增两次

    // 输出可能的结果
    cout << "After increment, i = " << i << ", j = " << j << ", max_inc = " << max_inc << endl;

    // 更安全的做法是避免在宏参数中使用有副作用的表达式
    int k = 5;
    int l = 10;
    int temp_k = k++;
    int temp_l = l++;
    int safe_max_inc = MAX(temp_k, temp_l); // 使用临时变量来避免副作用

    // 输出结果
    cout << "After using temporary variables, k = " << k << ", l = " << l << ", safe_max_inc = " << safe_max_inc << endl;

    return 0;
}
