#include <iostream>
using namespace std;

int a[1000006] = {0};

int left_bound(int a[], int left, int right, int target)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) { // 注意这里的变化
            if (mid == left || a[mid - 1] != target) { // 已经是最左边的元素了
                return mid;
            } else { // 左边还有相同的元素，继续查找
                right = mid - 1;
            }
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    	cin >> a[i];

	while (m--) {
		int q;
		cin >> q;

		// 注意左边界是从1开始的
		cout << left_bound(a, 1, n, q);
		if (m > 0)
			cout << ' ';
		else
			cout << endl;
	}

    return 0;
 }
