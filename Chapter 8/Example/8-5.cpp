// 题目 UVA 11054：https://cn.vjudge.net/problem/UVA-11054

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        long long ans = 0, last = 0, temp;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            ans += abs(last);
            last += temp;
        }
        cout << ans << endl;
    }
    return 0;
}