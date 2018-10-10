// 题目 UVA 11059 ：https://cn.vjudge.net/problem/UVA-11059

#include <iostream>
using namespace std;

const int maxn = 18;

int main()
{
    int kcase = 0, n;
    while (cin >> n)
    {
        int data[maxn];
        for (int i = 0; i < n; ++i)
        {
            cin >> data[i];
        }

        long long max = 0; // 最大乘积
        for (int i = 0; i < n; ++i)
        {
            int numOfNegative = 0;
            int position = i;
            int j;
            // 找序列终点
            for (j = i; j < n; ++j)
            {
                if (data[j] < 0)
                {
                    ++numOfNegative;
                    // 奇数个负数
                    if (numOfNegative % 2)
                    {
                        position = j - 1;
                    }
                }
                else if (data[j] == 0)
                {
                    break;
                }
            }

            long long max1 = 0;
            // 起点不为0
            if (data[i] != 0)
            {
                if (numOfNegative % 2)
                { // 奇数个负数，终点为最后一个负数的前一个
                    if (position < i)
                    { // 起点为负数
                        max1 = 0;
                    }
                    else
                    {
                        max1 = 1;
                        for (int k = i; k <= position; ++k)
                        {
                            max1 *= data[k];
                        }
                    }
                }
                else
                { // 偶数个负数
                    max1 = 1;
                    for (int k = i; k < j; ++k)
                    {
                        max1 *= data[k];
                    }
                }
            }

            if (max1 > max)
            {
                max = max1;
            }
        }
        cout << "Case #" << ++kcase << ": The maximum product is " << max << '.' << endl
             << endl;
    }

    return 0;
}