/**
 *
 * @File:   make_heap.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-25
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>

int main ()
{
	std::vector<int> h {1, 6, 4, 5, 9, 7, 8};
	// make max heap (default)
	make_heap(begin(h), end(h));
	for (int x : h) 
		std::cout << x << ' ';  // 9 6 8 2 1 7 4
	std::cout << '\n';

	// make min heap
	make_heap(begin(h), end(h), std::greater<>{});
	for (int x : h) 
		std::cout << x << ' ';  // 9 6 8 2 1 7 4
	std::cout << '\n';
	return 0;
}
