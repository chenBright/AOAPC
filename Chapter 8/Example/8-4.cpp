// 题目 UVA 11134 ：https://cn.vjudge.net/problem/UVA-11134
// 贪心算法

/* TODO
 * 看不懂
 * 感觉结果与贪心策略不相符
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5000 + 5;
int n, xl[maxn], yl[maxn], xr[maxn], yr[maxn], x[maxn], y[maxn];

bool solve(int *a, int *l, int *r, int n)
{
    fill(a, a + n, -1);

    //mr为包含k的区间最小右界，cur为放k的最优区间
    int cur, mr;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < 0 && l[i] <= k && r[i] < mr)
            {
                cur = i;
                mr = r[cur];
            }
        }
        if (cur < 0 || k > mr)
        {
            return false;
        }
        a[cur] = k;
    }
    return true;
}

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);
        }
        if (solve(xl, xr, x, n) && solve(yl, yr, y, n))
        {
            for (int i = 0; i < n; ++i)
            {
                printf("%d %d\n", x[i], y[i]);
            }
        }
        else
        {
            printf("IMPOSSIBLR\n");
        }
    }

    return 0;
}