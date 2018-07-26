// 题目 UVa 10935 ：https://cn.vjudge.net/problem/UVA-10935

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n; // 牌数
    while (scanf("%d", &n) != EOF && n)
    {
        queue<int> q1; // 剩余纸牌队列
        for (int i = 0; i < n; ++i)
        {
            q1.push(i + 1);
        }

        cout << "Discarded cards: ";
        bool isFirst = true;
        while (q1.size() > 1)
        {
            int first;
            first = q1.front();
            q1.pop();

            if (isFirst)
            {
                cout << first;
                isFirst = !isFirst;
            }
            else
            {
                cout << ", " << first;
            }

            first = q1.front();
            q1.pop();
            q1.push(first);
        }
        cout << endl;

        cout << "Remaining card: " << q1.front() << endl;
    }

    return 0;
}
