/**
 *
 * @File:   remove.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-25
 *
 */
#include <iostream>
#include <deque>
using namespace std;

// 输出deque全部元素
void display_deque(deque<int> dq){
    for (const int& num : dq)
        cout << num << ", ";
    cout << endl;
}

int main() {
    deque<int> nums {1, 2, 3};

    cout << "Initial Deque: ";
    display_deque(nums);

    nums.pop_back();
    cout << "Deque after pop_back(): ";
    display_deque(nums);

    nums.pop_front();
    cout << "Deque after pop_front(): ";
    display_deque(nums);

    return 0;
}


