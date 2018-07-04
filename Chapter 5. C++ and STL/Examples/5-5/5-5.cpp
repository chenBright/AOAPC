// 题目  UVa 12096 ：https://cn.vjudge.net/problem/UVA-12096

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
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
		if (op[0] == 'p') {
			s.push(ID(Set()));
		}
	}
}
