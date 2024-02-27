#include <algorithm>
#include <iostream>
using namespace std;
int mymap[210][210];
int n, m;
bool visited[210][210];
int maxd = -1;
int dfs(int a, int b) {
    if (a < 1 || a > n) return 0;
    if (b < 1 || b > m) return 0;
    visited[a][b] = true;
    int d1, d2, d3, d4;
    d1 = d2 = d3 = d4 = 0;
    if (visited[a - 1][b] == false && mymap[a - 1][b] != 0) d1 = dfs(a - 1, b);
    if (visited[a + 1][b] == false && mymap[a + 1][b] != 0) d2 = dfs(a + 1, b);
    if (visited[a][b - 1] == false && mymap[a][b - 1] != 0) d3 = dfs(a, b - 1);
    if (visited[a][b + 1] == false && mymap[a][b + 1] != 0) d4 = dfs(a, b + 1);
    if (d1 == -1 || d2 == -1 || d3 == -1 || d4 == -1) return -1;
    if (mymap[a][b] == -1) return -1;
    return d1 + d2 + d3 + d4 + mymap[a][b];
}
int main() {
    cin >> n >> m;
    fill(visited[0], visited[0] + 210 * 210, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mymap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] == false && mymap[i][j] != 0) {
                int curd = dfs(i, j);
                maxd = max(curd, maxd);
            }
        }
    }
    maxd = max(maxd, 0);
    cout << maxd;
    return 0;
}