// 题目 UVa 1595 ：https://cn.vjudge.net/problem/UVA-1595

#include <iostream>
#include <set>
using namespace std;

// 坐标点
struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const Point &rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

set<Point> dots;

int main()
{
    int T; // 测试用例的数量
    cin >> T;

    int N; // 测试用例的点的个数
    while (cin >> N)
    {
        dots.clear(); // 清空dots

        for (int i = 0; i < N; ++i)
        {
            Point p;
            cin >> p.x >> p.y;
            dots.insert(p); // 按横坐标排序好的坐标点set
        }

        bool isSymmetry = true;
        int s = dots.begin()->x + dots.end()->x; // 如果对称，对应点相加是同一个值

        set<Point>::iterator it;
        for (int it = dots.begin(); it != dots.end(); ++it)
        {
            Point p(s - it->x, it->y);
            if (!dots.count(p))
            {
                isSymmetry = false;
                break;
            }
        }

        if (isSymmetry)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}