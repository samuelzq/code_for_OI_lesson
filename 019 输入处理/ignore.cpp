#include <iostream>
#include <ios> 
#include <limits> 
using namespace std; 

int main() 
{ 
	int x;
	char str[80];
	cout << "Enter a number and string:\n";
	cin >> x;

	// 清空输入缓冲区中当前的所有换行符
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cin.getline(str, 80);
	cout << "You have entered:\n";
	cout << x << endl;
	cout << str << endl;

	return 0; 
}

