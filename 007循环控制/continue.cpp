#include <iostream>

using namespace std;

int main(void)
{
	for (int i = 0; i < 10; ++i) {
	    if (i == 5) {
	        continue;  // 当i等于5时跳过本次循环，继续下一次循环
	    }
	    cout << i << endl;
	}
	return 0;
}