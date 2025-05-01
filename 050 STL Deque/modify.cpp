/**
 *
 * @File:   modify.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-25
 *
 */
#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> nums = {1, 2};

    cout << "Initial Deque: ";

    for (const int& num : nums)
      cout << num << ", ";

    // 更新索引为0和1的元素
    nums.at(0) = 3;
    nums.at(1) = 4;

    cout << "\nUpdated Deque: ";

    for (const int& num : nums)
        cout << num << ", ";
    cout << endl;
    return 0;
}
