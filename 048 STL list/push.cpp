/**
 *
 * @File:   push.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-11
 *
 */
#include <iostream>
#include <list>

using namespace std;

int main() {
    // 创建一个空的整数列表
    list<int> myList;

    // 使用push_back()在列表末尾添加元素
    myList.push_back(10); // 在列表末尾添加元素10
    myList.push_back(20); // 在列表末尾添加元素20

    // 使用push_front()在列表开头添加元素
    myList.push_front(5); // 在列表开头添加元素5

    // 使用insert()在指定位置之前插入元素
    // 创建一个迭代器指向列表的第二个元素（值为20的位置）
    auto it = myList.begin();
    myList.insert(it, 15);   // 等效于push_front()

    // 在第二个元素前插入元素14
    // 注意此时it指向的是第二个元素了
    myList.insert(it, 14);

    // 输出列表内容
    cout << "列表内容: ";
    for (int num : myList) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
