#include <bits/stdc++.h>
using namespace std;

int a[10004];

int main(void)
{
    int n, cnt;

    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];

	cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			int temp;
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
    return 0;
}