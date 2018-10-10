// 题目 UVA 12657 ：https://cn.vjudge.net/problem/UVA-12657

// TODO
// 提交到OJ上，反馈“Wrong answer”
// 但本地跑了几个例子，都正确
// 且代码与书上基本一致
// 应该是多了回车符之类的

#include <cstdio>

const int maxn = 100005;
int left[maxn], right[maxn]; // left[i]和right[i] 表示编号为i的盒子左边和右边的编号

void link(int l, int r)
{
    left[r] = l;
    right[l] = r;
}

int main()
{
    int n, m, kcase = 0;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        right[0] = 1;
        left[0] = n;

        int op, X, Y;
        bool inv = false;

        while (m--)
        {
            scanf("%d", &op);
            if (op == 4)
            {
                inv = !inv;
            }
            else
            {
                scanf("%d%d", &X, &Y);
                if (op == 1)
                {
                    if (op == 3 && right[Y] == X)
                    { // 交换X、Y，方便后面判断交换是否相邻
                        int temp = X;
                        X = Y;
                        Y = temp;
                    }
                    if (op != 3 && inv)
                    { // 链表已反转
                        op = 3 - op;
                    }
                    if (op == 1 && X == left[Y])
                    { // X已经在Y左边
                        continue;
                    }
                    if (op == 2 && X == right[Y])
                    { // X已经在Y右边
                        continue;
                    }

                    int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                    if (op == 1)
                    {
                        link(LX, RX);
                        link(LY, X);
                        link(X, Y);
                    }
                    else if (op == 2)
                    {
                        link(LX, RX);
                        link(Y, X);
                        link(X, RY);
                    }
                    else if (op == 3)
                    {
                        if (right[X] == Y)
                        {
                            link(LX, Y);
                            link(Y, X);
                            link(X, RY);
                        }
                        else
                        {
                            link(LX, Y);
                            link(Y, RX);
                            link(LY, X);
                            link(X, RX);
                        }
                    }
                }
            }
        }

        int b = 0;
        long long sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            b = right[b];
            if (b % 2)
            {
                sum += b;
            }
        }
        // 反转后，所求为剩下数字值和，即 总和 - sum
        if (inv && n % 2 == 0)
        {
            sum = (long long)n * (n + 1) / 2 - sum;
        }
        printf("Case %d: %lld\n", ++kcase, sum);
    }

    return 0;
}
