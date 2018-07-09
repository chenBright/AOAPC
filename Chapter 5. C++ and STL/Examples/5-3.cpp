// 题目 UVa 10815 ：https://cn.vjudge.net/problem/UVA-10815

#include <iostream>
#include <string>
#include <set>
#include <sstream>
    using namespace std;

set<string> dist; // string集合

int main() {
    string s, buf;
    while (cin >> s) {
        for (int i = 0; i < s.length(); ++i) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            }
            else {
               s[i] = ' '; 
            }
        }
        stringstream ss(s);
        while (ss >> buf) {
            dist.insert(buf);
        }
    }

    for (set<string>::iterator it = dist.begin(); it != dist.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}