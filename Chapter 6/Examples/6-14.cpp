// 题目 UVA 816 ：https://cn.vjudge.net/problem/UVA-816

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 10;

struct Node {
    int r, c, dir;
    Node(int r = 0, int c = 0, int dir = 0): r(r), c(c), dir(dir) {}
};

const char* dirs = "NESW"; // 顺时针旋转
const char* turns = "FLR";

// 把方向字符转化为0~3，分别对应NESW
int dirID(char c) {
    return strchr(dirs, c) - dirs;
}

// 把转向字符转化为0~2，分别对应FLR
int turnID(char c) {
    return strchr(turns, c) - turns;
}

int hasEdge[maxn][maxn][4][3]; // 表示当前状态是(r,c,dir)是否可以沿着转向turn行走
int d[maxn][maxn][4];
Node p[maxn][maxn][4];
int r0, c0, dir, r1, c1, r2, c2;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = { 0, 1, 0, -1};

Node walk(const Node& u, int turn) {
    int dir = u.dir;
    if (turn == 1) {
        dir = (dir + 3) % 4; // 逆时针左转
    } else if (turn == 2) {
        dir = (dir + 1) % 4; // 顺时针右转
    }
    return Node(u.r + dr[dir], u.c + dc[dir], dir);
}
bool inside(int r, int c)
{ // 是否出界
    return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

bool readCase() // 读取数据
{
    char s[99], s2[99];
    scanf("%s", s);
    char errs[99] = "END";
    if (strlen(s) == 3 && s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
    {
        return false;
    }
    scanf("%d%d%s%d%d", &r0, &c0, s2, &r2, &c2);

    printf("%s\n", s);

    dir = dirID(s2[0]);
    r1 = r0 + dr[dir];
    c1 = c0 + dc[dir];

    memset(hasEdge, 0, sizeof(hasEdge));
    while (1)
    {
        int r, c;
        scanf("%d", &r);
        if (r == 0)
        {
            break;
        }
        scanf("%d", &c);
        while (scanf("%s", s) == 1 && s[0] != '*')
        {
            for (int i = 1; i < strlen(s); i++)
            {
                hasEdge[r][c][dirID(s[0])][turnID(s[i])] = 1;
            }
        }
    }
    return true;
}

void printAns(Node u) // 打印最短路
{
    vector<Node> nodes;

    while (1)
    {
        nodes.push_back(u);
        if (d[u.r][u.c][u.dir] == 0)
        {
            break;
        }
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0, c0, dir));

    int cnt = 0;
    for (int i = nodes.size() - 1; i >= 0; i--)
    {
        if (cnt % 10 == 0)
        {
            printf(" ");
        }
        printf(" (%d,%d)", nodes[i].r, nodes[i].c);
        if (++cnt % 10 == 0)
        {
            printf("\n");
        }
    }
    if (nodes.size() % 10 != 0)
    {
        printf("\n");
    }
}

void solve()
{
    queue<Node> q;
    memset(d, -1, sizeof(d));
    Node u(r1, c1, dir);
    d[u.r][u.c][u.dir] = 0;
    q.push(u);
    while (!q.empty())
    {
        Node u = q.front();
        q.pop();
        if (u.r == r2 && u.c == c2)
        { // 终点
            printAns(u);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            Node v = walk(u, i);
            if (hasEdge[u.r][u.c][u.dir][i] &&
                inside(v.r, v.c) &&
                d[v.r][v.c][v.dir] < 0)
            {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}

int main()
{
    while (readCase())
    {
        solve();
    }

    return 0;
}