#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char map[310][310];
vector<char> temp;
int cnt = 0;
int n, m;
void dfs(int i, int j) {
    if (i > n || j > m) return;
    if (map[i][j] == '*') return;
    temp.push_back(map[i][j]);
    if (i == n && j == m) {
        if (count(temp.begin(), temp.end(), '#') == 2) cnt++;
        temp.pop_back();
        return;
    }
    if (i + 1 <= n && map[i + 1][j] == '#') {
        dfs(i + 1, j);
        temp.pop_back();
        return;
    }
    if (j + 1 <= m && map[i + 1][j] == '#') {
        dfs(i, j + 1);
        temp.pop_back();
        return;
    }
    if (i + 1 <= n && map[i + 1][j] != '*') dfs(i + 1, j);
    if (j + 1 <= m && map[i][j + 1] != '*') dfs(i, j + 1);
    temp.pop_back();
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    dfs(1, 1);
    cout << cnt;
    return 0;
}