/**
 *
 * @File:   left_bound.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-08-25
 *
 */
#include <iostream>
using namespace std;

int left_bound(int a[], int left, int right, int target)
{
	int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) { // 注意这里的变化
	    	ans = mid;
	    	right = mid - 1;
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(void)
{
    int a[] = {1, 2, 2, 2, 5}; // 6
    int b = 2;

    // 注意第三个参数
    cout << b << "最小的序号是  " << left_bound(a, 0, 4, b) << endl;
    return 0;
 }
