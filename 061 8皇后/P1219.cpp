/**
 *
 * @File:   P1219.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-03
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查在当前位置放置皇后是否安全
bool isSafe(const vector<int>& queens, int row, int col) {
  for (int prevRow = 0; prevRow < row; ++prevRow) {
    int prevCol = queens[prevRow];
    if (prevCol == col || abs(prevRow - row) == abs(prevCol - col)) {
      return false;
    }
  }
  return true;
}

// 递归函数，用于解决 N 皇后问题
void solveNQueens(vector<int>& queens, int row, int &count) {
  int n = queens.size();
  if (row == n) {
	// 找到一个解，输出并计数
    count++;
    if (count > 3) {
      return; // 找到 3 个解就退出
    }
    for (int col : queens) {
      cout << col + 1 << " ";
    }
    cout << endl;
    return;
  }

  for (int col = 0; col < n; ++col) {
    if (isSafe(queens, row, col)) {
      queens[row] = col;
      solveNQueens(queens, row + 1, count);
    }
  }
}

int main() {
  int n = 6;
  cin >> n;
  vector<int> queens(n);
  int count = 0;

  solveNQueens(queens, 0, count);

  // 输出解的总个数
  cout << count << endl;

  return 0;
}
