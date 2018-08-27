// 题目 UVA 839 ：https://cn.vjudge.net/problem/UVA-839

#include <iostream>
using namespace std;

// 深度优先搜索
bool solve(int &W)
{
    int W1, D1, W2, D2;
    cin >> W1 >> D1 >> W2 >> D2;

    bool b1 = true, b2 = true;
    if (!W1)
    {
        b1 = solve(W1);
    }
    if (!W2)
    {
        b2 = solve(W2);
    }
    W = W1 + W2;

    return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main()
{
    int T, W;
    cin >> T;
    while (T--)
    {
        if (solve(W))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        if (T)
        {
            cout << endl;
        }
    }

    return 0;
}
