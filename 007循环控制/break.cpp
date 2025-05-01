#include <iostream>

using namespace std;

int main(void)
{
	for (int i = 0; i < 10; ++i) {
	    if (i == 5) {
	        break;  // 当i等于5时退出循环
	    }
	    cout << i << endl;
	}
	return 0;
}