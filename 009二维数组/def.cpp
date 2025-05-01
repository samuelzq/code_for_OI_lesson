#include <iostream>
using namespace std;

int main() {
    int rows = 3;
    int cols = 4;
    int array[rows][cols];

    cout << "请输入一个" << rows << "行" << cols << "列的二维数组：" << endl;

    // 循环接收用户输入的数组元素
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "请输入第" << i + 1 << "行" << "第" << j + 1 << "列的元素：";
            cin >> array[i][j];
        }
    }

    // 打印接收到的二维数组
    cout << "你输入的二维数组是：" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            cout << array[i][j] << ' ';
        }
        cout << array[i][cols - 1] << endl;
    }
    // 访问特定位置的元素
    int firstRowFirstCol = array[0][0]; // 访问第一行第一列的元素，值为1
    int secondRowThirdCol = array[1][2]; // 访问第二行第三列的元素，值为7

    cout << "第一行第一列的元素：" << firstRowFirstCol << endl;
    cout << "第二行第三列的元素：" << secondRowThirdCol << endl;

    return 0;
}
