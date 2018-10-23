// 题目 UVA 11572://cn.vjudge.net/problem/UVA-11772

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 1000000 + 5;
int A[maxn];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &A[i]);
        }

        set<int> s;
        int L = 0, R = 0, ans = 0;
        while (R < n)
        {
            if (!s.count(A[R]))
            {
                s.insert(A[R++]);
            }
            else
            {
                s.erase(A[L++]);
            }
            ans = max(ans, R - L);
        }
        printf("%d\n", ans);
    }

    return 0;
}