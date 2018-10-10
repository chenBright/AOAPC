// 题目 UVA 548 ：https://cn.vjudge.net/problem/UVA-548

/**
 * TODO
 * 数组版本的二叉树实现
 */

#include <iostream>
#include <sstream>
#include <climits>
using namespace std;

struct Node
{
    int val;
    Node *leftNode, *rightNode;
    Node() : leftNode(nullptr), rightNode(nullptr)
    {
    }
};

const int maxn = 10000 + 10;
Node *root;
int inOrder[maxn], postOrder[maxn];
int i; // 结点数量
int bestNode, bestSum;

Node *newNode()
{
    return new Node();
}

Node *build(int in_low, int in_high, int post_low, int post_high)
{
    if (in_low > in_high)
    {
        return nullptr;
    }

    Node *node = newNode();
    int val = postOrder[post_high];
    node->val = val;
    int position = 0;
    while (inOrder[position] != val)
    {
        ++position;
    }
    int count = position - in_low; // 左子树的节点数
    node->leftNode = build(in_low, position - 1, post_low, post_low + count - 1);
    node->rightNode = build(position + 1, in_high, post_low + count, post_high - 1);
    return node;
}

void removeTree(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    removeTree(node->leftNode);
    removeTree(node->rightNode);
    delete node;
}

bool readInput(int *arr)
{
    string line;
    if (!getline(cin, line))
    {
        return false;
    }

    stringstream ss1(line);

    i = 0;
    int n;
    while (ss1 >> n)
    {
        arr[i++] = n;
    }
    return i > 0;
}

void dfs(Node *node, int sum)
{
    if (!node)
    {
        return;
    }

    sum += node->val;
    if (!node->leftNode && !node->rightNode)
    {
        if (sum < bestSum || (sum == bestSum && node->val < bestNode))
        {
            bestSum = sum;
            bestNode = node->val;
        }
    }

    dfs(node->leftNode, sum);
    dfs(node->rightNode, sum);
}

int main()
{
    while (readInput(inOrder))
    {
        readInput(postOrder);
        Node *root;
        root = build(0, i - 1, 0, i - 1);
        bestSum = INT_MAX;
        dfs(root, 0);
        removeTree(root);
        cout << bestNode << endl;
    }
    return 0;
}
