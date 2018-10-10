// 题目 UVA 506 ：https://cn.vjudge.net/problem/UVA-506

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int cnt = 0;
map<string, int> name2id;
map<int, string> id2name;

vector<int> depend[maxn];
vector<int> depend2[maxn];

int status[maxn];
vector<int> installed;

int id(const string &name)
{
    if (name2id.count(name))
    {
        return name2id[name];
    }
    int d = name2id.size();
    name2id[name] = d;
    id2name[d] = name;
    return d;
}

string &name(const int &id)
{
    return id2name[id];
}

void list()
{
    vector<int>::iterator it;
    for (it = installed.begin(); it != installed.end(); ++it)
    {
        cout << "   " << name(*it) << endl;
    }
}

void setDepend(istringstream &ss)
{
    string s1, s2;
    ss >> s1;
    int id1 = id(s1);
    while (ss >> s2)
    {
        int id2 = id(s2);
        depend[id1].push_back(id2);
        depend2[id2].push_back(id1);
    }
}

void install(const int item, const bool isTopLevel)
{
    if (!status[item])
    {
        vector<int>::iterator it;
        for (it = depend[item].begin(); it != depend[item].end(); ++it)
        {
            install(*it, false);
        }
        cout << "   Installing " << name(item) << endl;
        status[item] = isTopLevel ? 1 : 2;
        installed.push_back(item);
    }
    else if (isTopLevel)
    {
        cout << "   " << name(item) << " is already installed." << endl;
    }
}

bool needed(int item)
{
    vector<int>::iterator it;
    for (it = depend2[item].begin(); it != depend2[item].end(); ++it)
    {
        if (status[*it])
        {
            return true;
        }
    }
    return false;
}

void remove(const int item, const bool isTopLevel)
{
    if (isTopLevel && !status[item])
    {
        cout << "   " << name(item) << " is not installed." << endl;
    }
    else if (isTopLevel && needed(item))
    {
        cout << "   " << name(item) << " is still needed." << endl;
    }
    else if ((isTopLevel || status[item] == 2) && !needed(item))
    {
        status[item] = 0;
        installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
        cout << "   Removing " << name(item) << endl;

        vector<int>::iterator it;
        for (it = depend[item].begin(); it != depend[item].end(); ++it)
        {
            remove(*it, false);
        }
    }
}

int main()
{
    int n;
    string line, cmd;
    memset(status, 0, sizeof(status));
    while (getline(cin, line))
    {
        cout << line << endl;
        istringstream ss(line);
        ss >> cmd;
        if (cmd[0] == 'E')
        {
            break;
        }

        string item1, item2;
        if (cmd[0] == 'L')
        {
            list();
        }
        else if (cmd[0] == 'D')
        {
            setDepend(ss);
        }
        else if (cmd[0] == 'I')
        {
            string s;
            ss >> s;
            install(id(s), true);
        }
        else if (cmd[0] == 'R')
        {
            string s;
            ss >> s;
            remove(id(s), true);
        }
    }

    return 0;
}