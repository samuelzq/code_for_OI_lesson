/**
 * https://www.luogu.com.cn/problem/P2073
 *
 * @File:   p2037.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-05-10
 *
 */
#include <bits/stdc++.h>

using namespace std;

struct Flower {
    int beauty, price;
    bool operator<(const Flower& f) const {
        return price < f.price; // 按价格排序
    }
};

int main(void)
{
	int o, w, p;
	set<Flower> flowers;
	
	while (1) {
		cin >> o;

		if (o == 1) {
			cin >> w >> p;
			flowers.insert({w, p});
		} else if (o == 2) {
			if (!flowers.empty()) {
				auto it = flowers.end();  // erase()方法需要接受正向迭代器 
				it--;
				flowers.erase(it);
			}
		} else if (o == 3) {
			if (!flowers.empty())
				flowers.erase(flowers.begin());
		} else if (o == -1) {
			int ws, ps;
			ws = ps = 0;
			for (auto flower : flowers) {
				ws += flower.beauty;
				ps += flower.price;
			}
			cout << ws << ' ' << ps << endl;
			break;
		}
	}
	return 0;
}
