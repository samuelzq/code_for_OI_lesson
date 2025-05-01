#include <iostream>

using namespace std;

int binary_search(int arr[], int left, int right, int target) {
	while (left <= right) {
		int mid = left + (right - left) / 2;  // （right+left)/2

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {  // arr[mid] > target
			right = mid - 1;
		}
	}
	return -1; // 目标未发现
}

int main(void)
{
	int sorted_array[] = {2, 5, 7, 8, 11, 12};
	int n = sizeof(sorted_array) / sizeof(sorted_array[0]);
	int target_value = 12;

	int result = binary_search(sorted_array, 0, n - 1, target_value);

	if (result != -1) {
		cout << "目标值 " << target_value << " 索引号 " << result << endl;
	} else {
		cout << "目标值 " << target_value << " 不存在" << endl;
	}

	return 0;
}
