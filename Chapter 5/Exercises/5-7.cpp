// 题目 UVa 12100 ：https://cn.vjudge.net/problem/UVA-12100

#include <iostream>
#include <queue>
using namespace std;

struct Task
{
    int id, priority, times = 0; // id、优先级
    Task(int id = 0, int priority = 0) : id(id), priority(priority) {}
    bool operator<(const Task &rhs) const
    {
        return priority < rhs.priority;
    }
};

int main()
{
    int T; // 测试同理数量
    cin >> T;
    while (T--)
    {
        queue<Task> q; // 打印队列
        int n, myId;   // 任务数、我的任务的id
        cin >> n >> myId;
        priority_queue<Task> tasks; // 优先队列
        // 初始化
        for (int i = 0; i < n; ++i)
        {
            int priority;
            cin >> priority;
            Task t(i, priority);
            q.push(t);
            tasks.push(t);
        }

        int time = 0; // 打印时间
        while (!q.empty())
        {
            Task topTask = q.front();
            Task priorTask = tasks.top();
            q.pop();
            if (topTask.priority >= priorTask.priority)
            { // 打印
                tasks.pop();
                ++time;
                if (topTask.id == myId)
                {
                    break;
                }
            }
            else
            {
                q.push(topTask);
            }
        }

        cout << time << endl;
    }

    return 0;
}