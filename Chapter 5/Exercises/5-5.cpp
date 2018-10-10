// 题目 UVa 10391 ：https://cn.vjudge.net/problem/UVA-10391

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<string> dictionary; // 字典
set<string>::iterator it; // 迭代器

int main()
{
    string str;
    // 初始化字典
    while (cin >> str)
    {
        dictionary.insert(str);
    }

    for (it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        string word = *it;
        auto len = word.length();
        // 遍历所有可能的组合
        for (int i = 1; i < len; ++i)
        {
            string str1 = word.substr(0, i);
            string str2 = word.substr(i, len - i);
            if (dictionary.count(str1) && dictionary.count(str2))
            {
                cout << word << endl;
                break;
            }
        }
    }

    return 0;
}