#include <iostream>
using namespace std;

int main() {
    int value; // 假设这是我们要检查的值

	cout << "请输入处理值：" << endl;
	cin >> value;
    cout << "处理值: " << value << endl;

    switch (value) {
        case 1:
            cout << "值是1" << endl;
            // fall through

        case 2:
            cout << "值是2" << endl;
            // fall through

        case 3:
            cout << "值是3" << endl;
            break; // 在这里中断，不继续执行下面的case

        default:
            cout << "值是其他值" << endl;
            break;
    }

    return 0;
}