// 题目 UVA 442 ：https://cn.vjudge.net/problem/UVA-442

#include <iostream>
#include <stack>
using namespace std;

struct Matrix {
    int row, col; // 行数、列数
    Matrix(int row = 0, int col = 0) : row(row), col(col) {}
} m[26]; // 输入的矩阵

int main() {
    int n; // 矩阵数量
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char name;
        cin >> name;
        cin >> m[name - 'A'].row >> m[name - 'A'].col;
    }

    string formula;
    while (cin >> formula) {
        if (formula.size() == 1) {
            cout << 0 << endl;
            continue;
        }

        stack<Matrix> matrixs;
        int sum = 0;
        bool isError = false;
        for (int i = 0; i < formula.size(); ++i) {
            char c = formula.at(i);
            if (c >= 'A' && c <= 'Z') {
                matrixs.push(m[c - 'A']);
            } else if (c == ')') {
                Matrix m1, m2;
                m1 = matrixs.top();
                matrixs.pop();
                m2 = matrixs.top();
                matrixs.pop();

                if (m2.col != m1.row) {
                    cout << "error" << endl;
                    isError = true;
                    break;
                } else {
                    sum += m2.row * m2.col * m1.col;
                    Matrix m3(m2.row, m1.col);
                    matrixs.push(m3);
                }
            }
        }

        if (!isError) {
            cout << sum << endl;
        }
    }

    return 0;
}