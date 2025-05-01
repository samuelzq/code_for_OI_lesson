#include <iostream>
#include <iomanip>
using namespace std;

void printArray(int array2D[][4], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << setw(3) << array2D[i][j];
        }
        cout << endl;
    }
}

int main() {
    const int ROWS = 3;
    int array2D[ROWS][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 调用函数打印二维数组
    printArray(array2D, ROWS);

    return 0;
}