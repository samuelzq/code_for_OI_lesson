#include <iostream>
#include <string>

using namespace std;

struct Rectangle {
	int width;
	int height;
};

int square(Rectangle& r)
{
	return r.width * r.height;
}

int main(void)
{
	struct Rectangle r;

	cout << "请输入宽：";
	cin >> r.width;
	cout << "请输入高：";
	cin >> r.height;

	cout << "矩形的面积是：" << square(r) << endl;
	return 0;
}