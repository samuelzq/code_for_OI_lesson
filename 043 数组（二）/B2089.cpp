#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}

	for(int i = a.size() - 1; i > 0; i--)
		cout << a[i] << ' ';
	cout << a[0] << endl;
	return 0;
}