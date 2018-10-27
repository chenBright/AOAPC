// 题目 UVA 10954://cn.vjudge.net/problem/UVA-10954
// 类似哈弗曼树建立过程

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int temp;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            q.push(temp);
        }

        int ans = 0;
        while (q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();

            ans += a + b;
            q.push(a + b);
        }
        cout << ans << endl;
    }
    return 0;
}