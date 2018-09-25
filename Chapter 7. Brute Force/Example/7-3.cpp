// 题目 UVA 10976 ：https://cn.vjudge.net/problem/UVA-10976

#include <iostream>
using namespace std;

int a[10011];
int b[10011];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int m = n << 1, count = 0;
        for (int i = n + 1; i <= m; ++i)
        {
            if (i * n % (i - n) == 0)
            {
                a[count] = i * n / (i - n);
                b[count] = i;
                count++;
            }
        }

        printf("%d\n", count);
        for (int i = 0; i < count; ++i)
            printf("1/%d = 1/%d + 1/%d\n", n, a[i], b[i]);
    }
    return 0;
}
