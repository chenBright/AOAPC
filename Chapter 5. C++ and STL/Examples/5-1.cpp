// 题目 UVa 10474 ：https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=1415

#include <cstdio>
using namespace std;

#include <algorithm>

const int maxn = 10000;

int main() {
	/**
	 * n 大理石数量
	 * q 问题数量
	 * x 每个问题问，大理石上写着的整数
	 * a 大理石数组
	 * kcase 问题序号
	 */
	int n, q, x, a[maxn], kcase = 0;

	// 循环测试多个例子
	while (scanf("%d%d", &n, &q) == 2 && n) {
		printf("CASE# %D\n", ++kcase);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
			// 排序
		sort(a, a + n);
		while (q--) {
			scanf("%d", &x);
			int p = lower_bound(a, a + n, x) - a; // 在已排序的数组a中查找x
			if (a[p] == x) {
				printf("%d found at %d\n", x, p);
			} else {
				printf("%d not found\n", x);
			}
		}
	}
	return 0;
}
