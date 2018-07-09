// 题目 UVa 540 ：https://cn.vjudge.net/problem/UVA-540

#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

const int maxt = 1000;

void enqueue(int teamId) {

}

void dequeue() {

}

int main() {
    int n, kcase = 0; // 团队数量、案例编号
    while (scanf("%d", &n) == 1 && n) {
        cout << "Scenario #" << ++kcase << endl;
        map<int, int> team; // 团队
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int member; // 成员
                cin >> member;
                team[member] = i;
            }
        }

        string operation; // 操作命令
        int id; // 进队成员的编号
        queue<int> q, q2[maxt]; // q是团队的队列， q2[i]是团队i成员的队列
        while (1) {
            cin >> operation;
            if (operation[0] == 'S') {
                break;
            } else if (operation[0] == 'E') {
                cin >> id;
                int t = team[id]; // 团队号
                if (q2[t].empty()) {
                    q.push(t);
                }
                q2[t].push(id);
            } else if (operation[0] == 'D') {
                int t = q.front();
                cout << q2[t].front() << endl;
                q2[t].pop();
                if (q2[t].empty()) {
                    q.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}

