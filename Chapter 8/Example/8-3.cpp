// 题目 UVA 1152 ：https://cn.vjudge.net/problem/UVA-1152

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 4000 + 10;
int num[4][maxn];
int sum[maxn * maxn];

int main()
{
    int T;
    bool isFirst = true;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);

        // 初始化
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        // 每一个集合一行
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                scanf("%d", &num[j][i]);
            }
        }

        int index = 0;
        // 前两个集合循环枚举
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sum[index++] = num[0][i] + num[1][j];
            }
        }
        // 排序，便于后面二分查找
        sort(sum, sum + index);

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int s = -(num[2][i] + num[3][j]);
                // 而烦恼查找
                cnt += upper_bound(sum, sum + index, s) - lower_bound(sum, sum + index, s);
            }
        }

        if (isFirst)
        {
            isFirst = false;
        }
        else
        {
            printf("\n");
        }
        printf("%d\n", cnt);
    }

    return 0;
}