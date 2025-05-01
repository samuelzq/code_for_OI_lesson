/**
 *
 * @File:   push.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-19
 *
 */
#include <iostream>
#include <queue>     // 包含队列容器库

using namespace std;

int main() {

  // 创建一个字符串类型的队列
  queue<string> animals;

  // 将元素推入队列
  animals.push("Cat");
  animals.push("Dog");

  cout << "Queue: ";

  // 打印队列中的元素
  // 循环直到队列为空
  while(!animals.empty()) { // 当队列不为空时执行循环

    // 打印当前元素
    cout << animals.front() << ", "; // 输出队列头部的元素

    // 从队列中弹出元素
    animals.pop(); // 移除队列头部的元素
  }

  cout << endl;

  return 0;
}
