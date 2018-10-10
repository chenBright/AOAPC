// 题目 UVA 572 ：https://cn.vjudge.net/problem/UVA-572

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int m, n, idx[maxn][maxn]; // 行、列、标记访问的数组
char pic[maxn][maxn];

// 深度优先搜索
void dfs(int row, int col, int id)
{
    // 越界的格子
    if (row < 0 || row >= m || col < 0 || col >= n)
    {
        return;
    }
    // 不是"@"或者已经访问过
    if (pic[row][col] != '@' || idx[row][col] > 0)
    {
        return;
    }

    idx[row][col] = id; // 访问
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i != 0 || j != 0)
            {
                dfs(row + i, col + j, id);
            }
        }
    }
}

int main()
{
    while (cin >> m >> n && n > 0 && m > 0)
    {
        for (int i = 0; i < m; ++i)
        {
            scanf("%s", pic[i]);
        }
        memset(idx, 0, sizeof(idx)); // 初始化
        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (idx[i][j] == 0 && pic[i][j] == '@')
                {
                    dfs(i, j, ++count);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}