/**
 *
 * @File:   modify.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-11
 *
 */
#include <iostream>
#include <list>

using namespace std;

int main() {
    // 创建一个整数列表并初始化
    list<int> myList = {10, 20, 30, 40, 50};

    // 输出原始列表
    cout << "原始列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    // 使用迭代器修改列表中的元素
    // 创建一个迭代器指向列表的开头
    auto it = myList.begin();

    // 修改第一个元素为15
    *it = 15;
    ++it; // 移动到下一个元素

    // 修改第三个元素为35, 由于已经移动了一次，再移动一次到达第三个元素（值为30的位置）
    advance(it, 1);
    *it = 35;

    // 输出修改后的列表
    cout << "修改后的列表: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    // 使用下标（不直接支持，但可以通过迭代器模拟）来修改元素（不推荐，仅作演示）
    // 注意：std::list不支持随机访问，所以不能用下标直接访问，这里只是为了演示如何“模拟”
    int indexToModify = 2; // 想要修改的元素的索引（从0开始）
    int newValue = 45; // 想要设置的新值
    int currentIndex = 0; // 当前迭代到的元素的索引

    // 遍历列表直到找到要修改的元素
    it = myList.begin();
    while (it != myList.end() && currentIndex < indexToModify) {
        ++it;
        ++currentIndex;
    }

    // 如果找到了要修改的元素
    if (it != myList.end()) {
        *it = newValue; // 修改元素的值
    } else {
        cout << "索引超出范围，无法修改元素。" << endl;
    }

    // 再次输出列表以确认修改
    cout << "再次修改后的列表（使用模拟下标）: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
