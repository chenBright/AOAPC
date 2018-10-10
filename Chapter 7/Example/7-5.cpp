// 题目 UVA 129 ：https://cn.vjudge.net/problem/UVA-129

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 100 + 10;
int n, L, cnt, A[maxn];

bool dfs(int cur)
{
    if (cnt++ == n)
    {
        for (int i = 0; i < cur; i++)
        {
            if (i && !(i % 64))
                printf("\n");
            if (i && !(i % 4) && i % 64)
                printf(" ");
            printf("%c", 'A' + A[i]);
        }
        printf("\n%d\n", cur);
        return false;
    }
    for (int i = 0; i < L; i++)
    {
        bool ok = true;
        A[cur] = i;
        for (int j = 1; j * 2 <= cur + 1; j++)
        {
            bool equal = true;
            for (int k = 0; k < j; k++)
                if (A[cur - k] != A[cur - k - j])
                {
                    equal = false;
                    break;
                }
            if (equal)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            if (!dfs(cur + 1))
                return false;
    }
    return true;
}

int main()
{
    while (cin >> n >> L && n)
    {
        cnt = 0;
        dfs(0);
    }
    return 0;
}