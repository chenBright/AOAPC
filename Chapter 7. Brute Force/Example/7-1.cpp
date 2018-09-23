// 题目 UVA 725 ：https://cn.vjudge.net/problem/UVA-725

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, kcase = 0;
    while (cin >> n && n)
    {
        int cnt = 0;

        if (kcase++)
        {
            cout << endl;
        }

        int divisor, dividend; // 除数、被除数
        for (divisor = 1234; divisor < 99999; ++divisor)
        {
            dividend = divisor * n;
            char buf[99];
            sprintf(buf, "%05d%05d", dividend, divisor);
            if (strlen(buf) > 10)
            {
                break;
            }

            bool flag = true;
            sort(buf, buf + 10); // 排序
            // 对比0-9
            for (int i = 0; i < 10; ++i)
            {
                if (buf[i] - '0' != i)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ++cnt;
                printf("%05d / %05d = %d\n", dividend, divisor, n);
            }
        }

        if (!cnt)
        {
            printf("There are no solutions for %d.\n", n);
        }
    }

    return 0;
}