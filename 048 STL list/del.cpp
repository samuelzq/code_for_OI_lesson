/**
 *
 * @File:   del.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-11
 *
 */
#include <iostream>
#include <list>

using namespace std;

int main() {
    // 创建一个整数列表并初始化
    list<int> myList = {1, 2, 3, 4, 5};

    // 使用pop_back()移除列表末尾的元素
    cout << "移除前的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    myList.pop_back(); // 移除末尾元素5

    cout << "使用pop_back()后的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    // 使用pop_front()移除列表开头的元素
    myList.pop_front(); // 移除开头元素1

    cout << "使用pop_front()后的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    // 使用erase()移除指定位置的元素
    auto it = myList.begin(); // 创建一个迭代器指向列表开头
    advance(it, 1); // 将迭代器向前移动一个位置，指向第二个元素（值为3）

    myList.erase(it); // 移除迭代器指向的元素（值为3）

    cout << "使用erase()后的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    // 使用remove()移除所有值为3的元素
    myList.push_back(3); // 先添加一个值为3的元素以便测试remove()
    myList.push_back(4); // 添加一个不为3的元素

    cout << "添加元素3和4后的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    myList.remove(4); // 移除所有值为4的元素

    cout << "使用remove(4)后的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    // 使用clear()清空列表
    myList.clear(); // 清空列表中的所有元素

    cout << "使用clear()后的列表是否为空? " << (myList.empty() ? "是" : "否") << endl;

    return 0;
}
