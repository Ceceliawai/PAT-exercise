#include <algorithm>
#include <iostream>
using namespace std;
bool visited[210];
bool e[210][210];
int main() {
    int N, M;
    cin >> N >> M;
    fill(e[0], e[0] + 210 * 210, false);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        e[x][y] = true;
        e[y][x] = true;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int K;
        int root;
        cin >> K >> root;
        fill(visited, visited + 210, false);
        visited[root] = true;
        int pre = root;
        bool flag = true;
        for (int j = 0; j < K - 1; j++) {
            int x;
            cin >> x;
            if (e[pre][x] == false) {
                flag = false;
            }
            if (visited[x] == true && x != root) {
                flag = false;
            }
            visited[x] = true;
            pre = x;
        }
        for (int i = 1; i <= N; i++) {
            if (visited[i] == false) flag = false;
        }
        if (pre != root) flag = false;
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}