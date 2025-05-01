#include <iostream>
using namespace std;

int main() 
{
	char name[5];

	// 实际读取3个输入字符
	cin.getline(name, 4);

	cout << name << endl;

	return 0;
}

