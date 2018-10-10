// 题目 UVa 1594 ：https://cn.vjudge.net/problem/UVA-1594

#include <iostream>
using namespace std;

int num[15]; // 第一个元组

bool check(int num[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (num[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T; // 测试实例个数
    cin >> T;
    while (T--)
    {
        int n; // 元组中元素个数
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }

        int count = 1000;
        while (count-- && !check(num, n))
        {
            int a1 = num[0];
            for (int i = 0; i < n; ++i)
            {
                if (i < n - 1)
                {
                    num[i] = abs(num[i] - num[i + 1]);
                }
                else
                {
                    num[i] = abs(num[i] - a1);
                }
            }
        }

        if (!check(num, n))
        {
            cout << "LOOP" << endl;
        }
        else
        {
            cout << "ZERO" << endl;
        }
    }

    return 0;
}
