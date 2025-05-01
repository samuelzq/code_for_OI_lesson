#include <iostream>

using namespace std;

int main(void)
{
    int a, b, out;
    char c;

	cin >> a >> b >> c;

	switch (c) {
        case '+':
            out = a + b;
            break;
        case '-':
            out = a - b;
            break;
        case '*':
            out = a * b;
            break;
        case '/':
        	if (b == 0) {
        		cout << "Divided by zero!" << endl;
        		return 0;
			}
            out = a / b;
            break;
        default:
            cout << "Invalid operator!" << endl;
            return 0;
    }
    cout << out << endl;
    return 0;
}