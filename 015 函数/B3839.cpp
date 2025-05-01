#include <bits/stdc++.h>

using namespace std;

int sum(int i)
{
	int ret = 0;
	ret = (1 + i) * i / 2;
	return ret;
}

int main(void)
{
    int n;
    int cnt;
	cin >> n;

	cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += sum(i);

	cout << cnt << endl;
    return 0;
}
