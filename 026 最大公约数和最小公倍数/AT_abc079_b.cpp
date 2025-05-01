#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL ln[100] = {2, 1};

LL luc(int n)
{
	if (ln[n])
		return ln[n];

	return ln[n] = luc(n - 1) + luc(n -2);
}

int main(void)
{
    int n;

    cin >> n;
    cout << luc(n) << endl;
    return 0;
}