// 题目 UVA 11988 ：https://cn.vjudge.net/problem/UVA-11988

#include <cstdio>
#include <cstring>
const int maxn = 100000 + 5;
int last, cur, next[maxn];
char s[maxn];

int main() {
    while (scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1);
        last =cur = 0;
        next[0] = 0;

        for (int i = 1; i <= n; ++i) {
            char ch = s[i];
            if (ch == '[') {
                cur = 0;
            } else if (ch == ']') {
                cur = last;
            } else {
                // 链表
                next[i] = next[cur]; // 插入
                next[cur] = i;
                if (cur == last) { 
                    last = i; // 更新"最后一个字符"的编号
                }
                cur = i; // 移动光标
            }
        }

        for (int j = next[0]; j != 0 ; j = next[j]) {
            printf("%c", s[j]);
        }
        printf("\n");
    }

    return 0;
}
