// 题目 UVa 1593 ：https://cn.vjudge.net/problem/UVA-1593

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxn = 1000;
string words[maxn][maxn]; //单词
int maxLen[maxn];         // 每列的宽度
int wordNum[maxn];        // 每行的单词数

void print(const string &s, int len, char ch)
{
    cout << s;
    for (int i = 0; i < len - (int)s.length(); ++i)
    {
        cout << ch;
    }
}

int main()
{
    string str, word;
    int i = 0, j;
    while (getline(cin, str))
    {
        stringstream ss(str);
        j = 0; // 每行的单词数
        while (ss >> word)
        {
            words[i][j] = word;
            maxLen[j] = max(maxLen[j], (int)word.length());
            ++j;
        }
        wordNum[i] = j;
        ++i; // 行数
    }

    for (int k = 0; k < i; ++k)
    {
        for (int l = 0; l < wordNum[k]; ++l)
        {
            if (l < wordNum[k] - 1)
            {
                // maxLen[l] + 1 表示单词之间用空格隔开
                print(words[k][l], maxLen[l] + 1, ' ');
            }
            else
            {
                cout << words[k][l] << endl;
            }
        }
    }

    return 0;
}
