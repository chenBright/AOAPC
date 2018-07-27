// 题目 UVa 10763 ：https://cn.vjudge.net/problem/UVA-10763

#include <cstdio>
#include <map>
using namespace std;

int n;
map<pair<int, int>, int> M;

int main() {
    while (scanf("%d", &n) != EOF && n)
    {
        M.clear();
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            M[make_pair(a, b)]++;
        }
        bool flag = true;
        map<pair<int, int>, int>::iterator it;
        for (it = M.begin(); it != M.end(); ++it)
        {
            if (it->second == 0)
                continue;
            pair<int, int> p = make_pair(it->first.second, it->first.first);
            if (M.find(p) == M.end() || M[p] != it->second)
            {
                printf("NO\n");
                flag = false;
                break;
            }
        }
        if (flag)
            printf("YES\n");
    }
    return 0;
}