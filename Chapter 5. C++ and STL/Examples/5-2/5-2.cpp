// 题目 UVa 101 : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=37

#include <iostream>
using namespace std;

#include <vector>
#include <string>

const int maxn = 30;
int n; // 木块
vector<int> pile[maxn];

// 找到木块a所在的pile和height
void findBlock(int a, int &p, int &h) {
	for (p = 0; p < n; ++p) {
		for (h = 0; h < pile[p].size(); ++h) {
			if (pile[p][h] == a) {
				return;
			}
		}
	}
}

// 把第p堆高度为h的木块上方的木块移回原地
void clearAbove(int p, int h) {
	for (int i = h + 1; i < pile[p].size(); ++i) {
		int block = pile[p][h];
		pile[block].push_back(block);
	}
	pile[p].resize(h + 1);
}

// 把第p堆高度为h及其上方的木块整体移动到p2堆的顶部
void pileOnto(int p, int h, int p2) {
	for (int i = h; i < pile[p].size(); ++i) {
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
}

// 打印
void print() {
	for (int i = 0; i < n; ++i) {
		printf("%d:", i);
		for (int j = 0; j < pile[i].size(); ++j) {
			printf(" %d", pile[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int a, b; // 木块
	cin >> n;
	// 初始化木块
	for (int i = 0; i < n; ++i) {
		pile[i].push_back(i);
	}

	string s1, s2; // 操作
	while (cin >> s1) {
		// 退出
		if (s1 == "quit") {
			break;
		}

		cin >> a >> s2 >> b;
		int pa, pb, ha, hb; // a、b所在的 pile 和 height
		findBlock(a, pa, ha);
		findBlock(b, pb, hb);

		// 非法指令
		if (pa == pb)  {
			continue;
		}
		if (s1 == "move") {
			clearAbove(pa, ha);
		}
		if (s2 == "onto") {
			clearAbove(pb, hb);
		}
		pileOnto(pa, ha, pb);
	}

	print();
	return 0;
}

