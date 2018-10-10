// 题目 UVA 536 ：https://cn.vjudge.net/problem/UVA-536

#include <iostream>
using namespace std;

string preOrder, inOrder;

/**
 * 后序遍历
 * @param l1 前序最小索引
 * @param h1 前序最大索引
 * @param l2 中序最小索引
 * @param h2 中序最大索引
 */
void build(int l1, int h1, int l2, int h2)
{
    if (l1 > h1)
    {
        return;
    }

    char root = preOrder[l1];
    int i;
    for (i = l2; inOrder[i] != preOrder[l1]; ++i)
        ;

    // 后序遍历
    build(l1 + 1, l1 + i - l2, l2, i - 1);
    build(l1 + i - l2 + 1, h1, i + 1, h2);
    cout << root;
}

int main()
{
    while (cin >> preOrder >> inOrder)
    {
        int len = preOrder.length();
        build(0, len - 1, 0, len - 1);
        cout << endl;
    }
    return 0;
}