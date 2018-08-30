// 题目 UVA 699 ：https://cn.vjudge.net/problem/UVA-699

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10000;
int sum[maxn];

void build(int pos)
{
    int v;
    cin >> v;
    if (v == -1)
    {
        return;
    }

    sum[pos] += v;
    build(pos - 1);
    build(pos + 1);
}

bool init()
{
    int v;
    cin >> v;
    while (v == -1)
    {
        return false;
    }

    memset(sum, 0, sizeof(sum));
    int pos = maxn / 2;
    sum[pos] = v;
    build(pos - 1);
    build(pos + 1);
    return true;
}

int main()
{
    int kcase = 0;
    while (init())
    {
        int pos = 0;
        while (sum[pos] == 0)
        {
            ++pos;
        }
        cout << "Case " << ++kcase << ":" << endl;
        cout << sum[pos++];
        while (sum[pos] != 0)
        {
            cout << " " << sum[pos++];
        }
        cout << endl
             << endl;
    }

    return 0;
}