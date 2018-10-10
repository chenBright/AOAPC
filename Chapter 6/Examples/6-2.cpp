// 题目 UVA 514 ：https://cn.vjudge.net/problem/UVA-514

#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
    while (cin >> n && n)
    {
        while (cin >> target[1] && target[1])
        {
            for (int i = 2; i <= n; ++i)
            {
                cin >> target[i];
            }

            int A = 1, B = 1;
            stack<int> station;
            bool ok = true;
            while (B <= n)
            {
                if (A == target[B])
                {
                    ++A;
                    ++B;
                }
                else if (!station.empty() && station.top() == target[B])
                {
                    station.pop();
                    ++B;
                }
                else if (A <= n)
                {
                    station.push(A++);
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
