/**
 *
 * @File:   8queen.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-04-03
 *
 */
#include <iostream>
#include <vector>

using namespace std;

// 检查在当前位置放置皇后是否安全
bool isSafe(vector<int>& queens, int row, int col) {
  for (int prevRow = 0; prevRow < row; ++prevRow) {
    int prevCol = queens[prevRow];
    // 检查是否在同一列或同一对角线上，两条对角线斜率绝对值为1
    if (prevCol == col || abs(prevRow - row) == abs(prevCol - col)) {
      return false;
    }
  }
  return true;
}

// 递归函数，用于解决八皇后问题
void solveNQueens(vector<int>& queens, int row, vector<vector<string>>& solutions) {
  int n = queens.size();
  if (row == n) {
    // 找到一个解决方案，将其转换为字符串形式并添加到结果中
    vector<string> solution;
    for (int i = 0; i < n; ++i) {
      string rowStr(n, '.');
      rowStr[queens[i]] = 'Q';
      solution.push_back(rowStr);
    }
    solutions.push_back(solution);
    return;
  }

  // 尝试在当前行的每一列放置皇后
  for (int col = 0; col < n; ++col) {
    if (isSafe(queens, row, col)) {
      queens[row] = col;
      solveNQueens(queens, row + 1, solutions);
    }
  }
}

// 主函数，用于调用递归函数并打印结果
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> solutions;
  vector<int> queens(n);  // 记录那些列上已经放置了皇后
  solveNQueens(queens, 0, solutions);
  return solutions;
}

int main() {
  int n = 8; // 八皇后问题
  vector<vector<string>> solutions = solveNQueens(n);

  // 打印所有解决方案
  for (const auto& solution : solutions) {
    for (const auto& row : solution) {
      cout << row << endl;
    }
    cout << endl;
  }

  return 0;
}
