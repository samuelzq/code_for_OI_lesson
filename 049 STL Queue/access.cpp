/**
 *
 * @File:   access.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-01-19
 *
 */
#include <iostream>
#include <queue>     // 包含队列容器库

using namespace std; // 使用标准命名空间

int main() {

  // 创建一个int类型的队列
  queue<int> nums;

  // 将元素推入队列
  nums.push(1);
  nums.push(2);
  nums.push(3);

  // 获取队列头部的元素
  int front = nums.front();
  cout << "第一个元素: " << front << endl;

  // 获取队列尾部的元素
  int back = nums.back();
  cout << "最后一个元素: " << back << endl;

  return 0;
}
