/**
 *
 * @File:   size.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-19
 *
 */
#include <iostream>
#include <queue>
using namespace std;

int main() {

  // 创建string类型队列
  queue<string> languages;

  // 王队列中插入三个元素
  languages.push("Python");
  languages.push("C++");
  languages.push("Java");

  // 获取当前队列中元素个数
  int size = languages.size();
  cout << "Size of the queue: " << size << endl;

  cout << "Queue is " << (languages.empty() ? "empty." : "not empty.") << endl;

  return 0;
}
