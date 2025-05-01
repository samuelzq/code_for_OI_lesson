#include <iostream>
using namespace std;

int main()
{
    int a = 20;
    int *pa = &a;
    int *pa1 = pa;
    cout << "The address of a is: " << pa << endl;
    cout << "The value of pa1 is: " << pa1 << endl;
    cout << "The value of *pa1 is: " << *pa1 << endl;
    return 0;
}
