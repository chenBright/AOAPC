// 题目 UVa 1592 ：https://cn.vjudge.net/problem/UVA-1592

#include <cstdio>
#include <string>
#include <map>
#include <utility>
using namespace std;

int n, m; // 行数、列数
int database[10010][15];
map<string, int> strToIntMap; // 字符串 - id map
map<pair<int, int>, int> colMap; // 二元组 - id map

int id = 0;
int strToInt(const string& str) {
	if (strToIntMap.count(str)) {
		return strToIntMap[str];
	} else {
		strToIntMap[str] = id;
		return id++;
	}
}

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		getchar(); // 换行符
		strToIntMap.clear();
		for (int i = 0; i < n; ++i) {
			string sub;
			char entry[128], comma;
			for (int j = 0; j < m - 1; ++j) {
				scanf("%[^,]%c", entry, &comma);
				database[i][j] = strToInt(string(entry));
			}
			scanf("%[^\n]", entry);
			getchar(); // 换行符
			database[i][m - 1] = strToInt(string(entry));
		}

		bool flag = true;
		for (int i = 0; i < m && flag; ++i) {
			for (int j = i + 1; j < m && flag; ++j) {
				colMap.clear();
				for (int k = 0; k < n && flag; ++k) {
					pair<int, int> p = make_pair(database[k][i], database[k][j]); // 二元组
					if (colMap.count(p)) {
						flag = false;
						printf("NO\n");
						printf("%d %d\n", colMap[p] + 1, k + 1);
						printf("%d %d\n", i + 1, j + 1);
					} else {
						colMap[p] = k;
					}
				}
			}
		}
		if (flag) {
			printf("YES\n");
		}
	}
	return 0;
}
