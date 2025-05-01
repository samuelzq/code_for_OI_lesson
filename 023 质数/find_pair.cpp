#include <iostream>
using namespace std;

void findPairsWithSum(int n, int targetSum) {
    for (int i = 1; i <= n - 1; ++i) { // 注意，我们只需要到n-1，因为j会从i+1开始
        for (int j = i + 1; j <= n; ++j) {
            if (i + j == targetSum) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

int main() {
    int n = 100;
    int targetSum = 100;
    findPairsWithSum(n, targetSum);
    return 0;
}