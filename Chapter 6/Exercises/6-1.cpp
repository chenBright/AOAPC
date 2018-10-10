// 题目 UVA 673 ：https://cn.vjudge.net/problem/UVA-673

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();

    stack<char> s;
    string str;
    bool isMatch;
    while (n--)
    {
        // 清空栈
        while (!s.empty())
        {
            s.pop();
        }
        isMatch = true;

        getline(cin, str);
        int len = str.length();
        if (len % 2)
        {
            cout << "No" << endl;
            continue;
        }

        for (int i = 0; i < len; ++i)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    cout << "No" << endl;
                    isMatch = false;
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    cout << "No" << endl;
                    isMatch = false;
                    break;
                }
            }
        }
        if (isMatch)
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}