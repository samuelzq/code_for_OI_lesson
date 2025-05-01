#include <iostream>
using namespace std;

int main()
{
    int a = 0x616263;
    int *pa = &a;
    char *pa1 = (char *)pa;
    cout << "The address of a is: " << pa << endl;
    cout << "The value of pa1 is: " << pa1 << "--" << (void *)pa1 << endl;
    cout << "The value of *pa1 is: " << *pa1 << endl;
    return 0;
}
