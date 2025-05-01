#include <iostream>
#include <list>

using namespace std;

int main ()
{
    // 按照描述的顺序使用构造函数：
    list<int> first;                                 // 一个空的整数列表
    list<int> second (4,100);                        // 包含四个值为100的整数的列表
    list<int> third (second);                        // second列表的一个副本
    list<int> fourth (second.begin(), second.end()); // 通过遍历second列表来构造

    // 迭代器构造函数也可以用来从数组构造列表：
    int myints[] = {16, 2, 77, 29};

    // 使用数组元素范围来构造列表
    list<int> fifth (myints + 1, myints + sizeof(myints) / sizeof(int));

    // 打印fifth列表的内容
    cout << "fifth列表的内容是： ";
    for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
