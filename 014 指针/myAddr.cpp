#include <iostream>
using namespace std;

int main()
{
    int a = 20;
    int *pa = &a;
    cout << "The address of a is: " << pa << endl;
    cout << "The address of pa is: " << &pa << endl;
    return 0;
}

