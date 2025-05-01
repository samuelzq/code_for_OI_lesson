/**
 * https://www.luogu.com.cn/problem/B3836
 *
 * @File:   B3836.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2024-07-27
 *
 */
#include <stdio.h>

int main(void)
{
    int x, y, z; // x代表公鸡数量，y代表母鸡数量，z代表小鸡数量
    int n, m;    // n 总钱数、m鸡的数目
    int cnt = 0; // 可能的方案数

	scanf("%d %d %d %d %d", &x, &y, &z, &n, &m);
	for (int i = 0; i <= n / x; i++) { // 公鸡最多 n / x 只
		for (int j = 0; j <= n / y; j++) { // 母鸡最多n / y 只
			int k = m - i - j; // 小鸡数量由总数减去公鸡和母鸡的数量得到
			if (k >= 0 && k % z == 0 && x * i + y * j + k / z == n) {
				// printf("公鸡：%d只, 母鸡：%d只, 小鸡：%d只\n", i, j, k);
				cnt++;
			}
		}
	}
    printf("%d\n", cnt);
    return 0;
}
