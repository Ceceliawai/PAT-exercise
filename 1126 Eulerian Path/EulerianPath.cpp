#include <algorithm>
#include <iostream>
using namespace std;
int e[510][510], degree[510];
bool visited[510];
int N;
void dfs(int root) {
    visited[root] = true;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false && e[root][i] == 1) {
            dfs(i);
        }
    }
}
int main() {
    fill(e[0], e[0] + 510 * 510, 0);
    fill(degree, degree + 510, 0);
    fill(visited, visited + 510, false);
    int M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        e[x][y] = 1;
        e[y][x] = 1;
        degree[x]++;
        degree[y]++;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i != 1) cout << " ";
        cout << degree[i];
        if (degree[i] % 2 != 0) cnt++;
    }
    cout << endl;
    dfs(1);
    for (int i = 1; i <= N; i++) {
        // 可能不是连通图
        if (visited[i] == false) {
            cout << "Non-Eulerian" << endl;
            return 0;
        }
    }
    if (cnt == 0)
        cout << "Eulerian";
    else if (cnt == 2)
        cout << "Semi-Eulerian";
    else
        cout << "Non-Eulerian";
    cout << endl;
    return 0;
}