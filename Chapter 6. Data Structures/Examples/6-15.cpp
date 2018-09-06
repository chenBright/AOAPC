// 题目 UVA 10305 ：https://cn.vjudge.net/problem/UVA-10305
// 参考 https://blog.csdn.net/shuangde800/article/details/7727280

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;

int visit[maxn];   // 访问标记数组
int topo[maxn], t; // 拓扑序列数组，索引
int G[maxn][maxn]; // 图
int m, n, a, b;

bool dfs(int u)
{
    visit[u] = -1; // 正在访问
    for (int v = 1; v <= n; ++v)
    {
        if (G[u][v])
        {
            if (visit[v] == -1)
            { // 存在环
                return false;
            }
            else if (!visit[v] && !dfs(v))
            { // 后面的访问失败
                return false;
            }
        }
    }
    // 结束访问
    visit[u] = 1;
    topo[--t] = u; // 最后把结点加到拓扑序列的首部（已递归完）

    return true;
}

bool topoSort()
{
    t = n;
    memset(visit, 0, sizeof(visit));
    for (int u = 1; u <= n; ++u)
    {
        if (!visit[u] && !dfs(u))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // 注意输入那里的结束条件不能是 n&&m,因为m可能是0
    while (~scanf("%d %d", &n, &m) && n + m)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            G[a][b] = 1;
        }

        if (topoSort())
        {
            cout << topo[0];
            for (int i = 1; i < n; ++i)
            {
                cout << ' ' << topo[i];
            }
            cout << endl;
        }
    }

    return 0;
}