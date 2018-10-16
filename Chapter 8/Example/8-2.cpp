// 题目 UVA 1605 ：https://cn.vjudge.net/problem/UVA-1605

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 50;
char b[2][maxn][maxn];

char Tochar(int x)
{
    if (x < 26)
    {
        return 'a' + x;
    }
    else
    {
        return 'A' + x - 26;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("2 %d %d\n", n, n);
        // 第一层第i行全是国家i
        for (int i = 0; i < n; ++i)
        {
            char c = Tochar(i);
            memset(b[0][i], c, sizeof(b[0][i]));
            // 第二层第j列全是国家j
            for (int j = 0; j < n; ++j)
            {
                b[1][j][i] = c;
            }
        }
        // 打印
        for (int h = 0; h < 2; ++h)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    putchar(b[h][i][j]);
                }
                puts("");
            }
            if (!h)
            {
                puts("");
            }
        }
    }

    return 0;
}