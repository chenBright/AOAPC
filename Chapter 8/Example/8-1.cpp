// 题目 UVA 120 ：https://cn.vjudge.net/problem/UVA-120

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int stack[101];
vector<int> ans;
int n;

/**
 * 在stack数组中搜索数字num
 * @param low 搜索范围最小索引
 * @param high 搜索范围最大索引
 * @param num 要搜索的数字
 * @return num在stack中的索引值
 */
int findNum(int low, int high, int num)
{
    for (int i = low; i <= high; ++i)
    {
        if (stack[i] == num)
        {
            return i;
        }
    }
}

/**
 * 翻转数组
 * @param low 最小索引
 * @param high 最大索引
 */
void reverse(int low, int high)
{
    int tmp;
    for (int i = low, j = high; i <= j; ++i, --j)
    {
        tmp = stack[i];
        stack[i] = stack[j];
        stack[j] = tmp;
    }
    cout << n - high << ' ';
}

// 排序富足函数，使降序排序
bool compare(int a, int b)
{
    return a > b;
}

// 判断stack数组是否有序
bool isSort()
{
    bool flag = true;
    for (int i = 1; i < n; ++i)
    {
        if (stack[i - 1] > stack[i])
        {
            flag = false;
        }
    }
    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    stringstream ss;
    while (getline(cin, s))
    {
        if (s.size() == 0)
        {
            break;
        }
        ans.clear();
        memset(stack, 0, sizeof(stack));

        int tmp;
        // 初始化
        n = 0;
        ss.clear();
        ss << s;
        while (ss >> tmp)
        {
            ans.push_back(tmp);
            stack[n++] = tmp;
        }
        cout << s << endl;

        // 排序
        sort(ans.begin(), ans.end(), compare);
        for (int i = 0; i < n; ++i)
        {
            if (isSort())
            {
                cout << 0 << endl;
                break;
            }

            // 最大值
            tmp = ans[i];
            int index = findNum(0, n - (i + 1), tmp);
            // 如果最大值不是第一个，则将其翻转到第一个
            if (index)
            {
                reverse(0, index);
            }
            // 将最大值翻转到正确位置
            reverse(0, n - (i + 1));
        }
    }

    return 0;
}