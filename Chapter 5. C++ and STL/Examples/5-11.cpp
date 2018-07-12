// 题目 UVa 814 ：https://cn.vjudge.net/problem/UVA-814

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

void parseAddress(const string& s, string& user, string& meta) {

}

int main() {
    int k;
    string s, t, user1, mta1, user2, mta2;
    set<string> addr;

    // 输入所有MTA，转化为地址
    while (cin >> s && s != "*") {
        cin >> s >> k;
        while (k--) {
            cin >> t;
            addr.insert(t + "@" + s);
        }
    }

    while (cin >> s && s != "*") {
        parseAddress(s, user1, mta1); // 处理发件人地址

        vector<string> mta; // 所有需要连接的mta，按照输入顺序排列
        map<string, vector<string>> dest; // 每个MTA需要发送的用户
        set<string> vis;
        while (cin >> t && t != "*") {
            parseAddress(t, user2, mta2);
            if (vis.count(t)) {
                continue;
            }
            vis.insert(t);
            if (!dest.count(mta2)) {
                mta.push_back(mta2);
                dest[mta2] = vector<string> ();
            }
            dest[mta2].push_back(t);
        }
        getline(cin, t); // 把"*"这一行的回车处理掉

        // 输入邮件正文
        string data;
        while (getline(cin, t) && t[0] != '*') {
            data += "   " + t + "\n";
        }

        for (int i = 0; i < mta.size(); ++i) {
            string mta2 = mta[i];
            vector<string> users = dest[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 << endl;
            cout << " HELO " << mta1 << "\n";
            cout << " 250\n";
            cout << " MAIL FORM:<" << s << ">\n";
            cout << " 250\n";
            bool ok = false;
            for (int i = 0; i < users.size(); ++i) {
                cout << " PCPT TO:<" << users[i] << ">\n";
                if (addr.count(users[i])) {
                    ok = true;
                    cout << " 250\n";
                } else {
                    cout << " 550\n";
                }
            }
            if (ok) {
                cout << " DATA\n";
                cout << " 354\n";
                cout << data;
                cout << ".\n";
                cout << " 250\n";
            }
            cout << " QUIT\n";
            cout << " 221\n";
        }
    }
    return 0;
}
