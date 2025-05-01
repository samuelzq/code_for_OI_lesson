/**
 *
 * @File:   right_bound.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-08-25
 *
 */
#include <iostream>
using namespace std;

int right_bound(int a[], int left, int right, int target)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) { // 注意这里的变化
            if (mid == right || a[mid + 1] != target) { // 已经是最右边的元素了
                return mid;
            } else { // 右边还有相同的元素，继续查找
                left = mid + 1;
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
    int a[] = {2, 2, 2, 2, 5};
    int b = 2;

    // 注意第三个参数
    cout << "最右边的 " << b << " 的序号是" << right_bound(a, 0, 4, b) << endl;
    return 0;
}
