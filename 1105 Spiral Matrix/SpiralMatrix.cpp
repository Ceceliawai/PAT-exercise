#include <algorithm>
#include <iostream>
using namespace std;
int N, m, n;
int number[10010];
int cnt = 0;
int RIGHT = 1;
int LEFT = 2;
int UP = 3;
int DOWN = 4;
bool mycmp(int x, int y) { return x > y; }
int main() {
    cin >> N;
    m = N;
    n = 1;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            int cm = max(i, N / i);
            int cn = min(i, N / i);
            if (cm >= cn && cm - cn < m - n) {
                m = cm;
                n = cn;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }
    sort(number, number + N, mycmp);
    int i = 0;
    int j = 0;
    int mat[m][n];
    fill(mat[0], mat[0] + m * n, -1);
    int d = RIGHT;
    while (cnt != N) {
        mat[i][j] = number[cnt];
        cnt++;
        if (cnt == N) break;
        if (d == RIGHT) {
            if (j + 1 < n && mat[i][j + 1] == -1)
                j++;
            else {
                i++;
                d = DOWN;
            }
        } else if (d == DOWN) {
            if (i + 1 < m && mat[i + 1][j] == -1)
                i++;
            else {
                j--;
                d = LEFT;
            }
        } else if (d == LEFT) {
            if (j - 1 >= 0 && mat[i][j - 1] == -1)
                j--;
            else {
                i--;
                d = UP;
            }
        } else if (d == UP) {
            if (i - 1 >= 0 && mat[i - 1][j] == -1)
                i--;
            else {
                j++;
                d = RIGHT;
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (j != 0) cout << " ";
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}