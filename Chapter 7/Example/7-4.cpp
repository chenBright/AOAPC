// 题目 UVA 524 ：https://cn.vjudge.net/problem/UVA-524

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 20;
int n;
int A[maxn], vis[maxn];

int isPrime(int N) {
    if (N < 2) {
        return false;
    }

    for (int i = 2; i * i<= N; ++i) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

void dfs(int cur) {
    if (cur == n && isPrime(A[1] + A[n])) {
        cout << A[1];
        for (int i = 2; i <= n; ++i) {
            cout << ' ' << A[i];
        }
        cout << endl;
    } else {
        for (int i = 2; i <= n; ++i) {
            if (!vis[i] && isPrime(i + A[cur])) {
                A[cur + 1] = i;
                vis[i] = 1; // 标记
                dfs(cur + 1);
                vis[i] = 0; // 清楚标记
            }
        }
    }
}

int main() {
    int kcase = 0;

    while (cin >> n) {
        if (kcase) {
            cout << endl;
        }

        cout << "Case " << ++kcase << ':' << endl;
        memset(vis, 0, sizeof(vis));
        A[1] = 1;
        dfs(1);
    }

    return 0;
}