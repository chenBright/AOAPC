// 题目 UVA 679 ：https://cn.vjudge.net/problem/UVA-679

/**
 * TODO
 * 1、超时（解决：P150）
 * 2、提交OJ，显示"Runtime error"
 */

#include <iostream>
using namespace std;

#include <cstring>
#include <cmath>

const int maxd = 20;
int s[1 << maxd]; // 移位运算，等于 2 ^ maxd - 1

int main()
{
    int l, D, I;
    cin >> l;
    while (l--)
    {
        cin >> D >> I;
        memset(s, 0, sizeof(s));
        int k = 1;
        int maxk = (int)pow(2, D) - 1;
        while (I--)
        {
            for (; k <= maxk;)
            {
                if (s[k])
                {
                    k = 2 * k + 1;
                }
                else
                {
                    k = 2 * k;
                }
                s[k] = !s[k];
            }
        }
        cout << k / 2 << endl;
    }

    return 0;
}
