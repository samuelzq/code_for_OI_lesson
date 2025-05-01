#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	vector<long long> a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		a.push_back(t);
	}

	for (int i = 0; i < n - 1; i++)
	   cout << 0 - a[i] << ' ';
	cout << 0 - a[n - 1] << endl;
	return 0;
}