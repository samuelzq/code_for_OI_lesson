/**
 *
 * @File:   access.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-25
 *
 */
#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> nums {1, 2, 3};

    cout << "Front element: " << nums.front() << endl;
    cout << "Back element: " << nums.back() << endl;
    cout << "Element at index 1: " << nums.at(1) << endl;
    cout << "Element at index 0: " << nums[0] << endl;

    return 0;
}
