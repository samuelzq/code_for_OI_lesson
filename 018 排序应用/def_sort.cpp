// A C++ program to demonstrate
// STL sort() using
// our own comparator
#include <bits/stdc++.h>
using namespace std;

// 间隔具有起和止两个属性
struct Interval {
	int start, end;
};

// 根据开始值比较间隔
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

int main()
{
	Interval arr[]
		= { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = sizeof(arr) / sizeof(arr[0]);

	// 根据开始值对间隔排序
	sort(arr, arr + n, compareInterval);

	cout << "Intervals sorted by start time : \n";
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i].start << "," << arr[i].end
			<< "] ";

	return 0;
}
