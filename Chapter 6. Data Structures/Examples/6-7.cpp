// 题目 UVA 122 ：https://cn.vjudge.net/problem/UVA-122

/**
 * TODO
 * 输出有问题 => 提交OJ显示"Wrong answer"
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
    bool haveValue;
    int val;
    Node *leftNode, *rightNode;
    Node() : haveValue(false), leftNode(nullptr), rightNode(nullptr)
    {
    }
};

const int maxn = 256 + 10;
Node *root;
char s[maxn];
bool failed; // 输入是否有误

Node *newNode()
{
    return new Node();
}

void addNode(int val, char *s)
{
    int len = strlen(s);
    Node *r = root;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == 'L')
        {
            if (r->leftNode == nullptr)
            {
                r->leftNode = newNode();
            }
            r = r->leftNode;
        }
        else if (s[i] == 'R')
        {
            if (r->rightNode == nullptr)
            {
                r->rightNode = newNode();
            }
            r = r->rightNode;
        }
    }
    // 已赋值，输入有误
    if (r->haveValue)
    {
        failed = true;
    }
    r->val = val;
    r->haveValue = true;
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

bool readInput()
{
    failed = false;
    root = newNode();
    while (1)
    {
        // 输入结束
        if (scanf("%s", s) != 1)
        {
            return false;
        }
        // 案例结束
        if (!strcmp(s, "()"))
        {
            break;
        }

        int v;
        sscanf(&s[1], "%d", &v); // 读入数字
        addNode(v, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<Node *> q;
    q.push(root);
    ans.clear();

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (!node->haveValue)
        {
            return false;
        }

        ans.push_back(node->val);
        if (node->leftNode)
        {
            q.push(node->leftNode);
        }
        if (node->rightNode)
        {
            q.push(node->rightNode);
        }
    }
    return true;
}

int main()
{
    while (readInput())
    {
        vector<int> ans;
        if (!failed && !bfs(ans))
        {
            puts("not complete");
        }

        int len = ans.size();
        for (int i = 0; i < len; i++)
        {
            printf("%d%c", ans[i], i == len - 1 ? '\n' : ' ');
        }

        removeTree(root);
    }

    return 0;
}
