// 题目  UVa 12096 ：https://cn.vjudge.net/problem/UVA-12096

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set, int> IDCache;
vector<Set> SetCache;

int ID(Set x) {
	if (IDCache.count(x)) {
		return IDCache[x];
	}
	SetCache.push_back(x);
	return IDCache[x] = SetCache.size() - 1;
}

int main() {
	stack<int> s;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string op;
		cin >> op;
		if (op[0] == 'P') {
			s.push(ID(Set()));
		} else if (op[0] == 'D') {
			s.push(s.top());
		} else {
			Set x1 = SetCache[s.top()];
			s.pop();
			Set x2 = SetCache[s.top()];
			s.pop();
			Set x;
			if (op[0] == 'U') {
				set_union(ALL(x1), ALL(x2), INS(x));
			}
			if (op[0] == 'I') {
				set_intersection(ALL(x1), ALL(x2), INS(x));
			}
			if (op[0] == 'A') {
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
	}
	cout << SetCache[s.top()].size() << endl;
}
