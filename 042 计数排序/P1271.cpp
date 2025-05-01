#include <iostream>
using namespace std;
int cnt[1000] = {0};

int main()
{
	int n, m, f = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		cnt[p]++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			if (f)
				cout << ' ';
			f = 1;
			cout << i;
		}
	}
	cout << endl;
	return 0;
}