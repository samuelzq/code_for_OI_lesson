/**
 *
 * @File:   insert.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-25
 *
 */
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> nums {2, 3}; // 声明并初始化一个整数类型的双端队列nums，初始包含2和3

    // 输出初始的双端队列内容
    cout << "Initial Deque: ";
    for (const int& num : nums) {
        cout << num << ", "; // 打印每个元素和一个逗号
    }

    // 在双端队列的末尾添加整数4
    nums.push_back(4);

    // 在双端队列的开头添加整数1
    nums.push_front(1);

    // 输出修改后的双端队列内容
    cout << "\nFinal Deque: ";
    for (const int& num : nums) {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}
