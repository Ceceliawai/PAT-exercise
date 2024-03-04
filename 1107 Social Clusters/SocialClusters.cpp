#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int e[10010][10010], N, K, id;
bool visited[10010];
vector<int> res;
set<int> s[10010];
int cnt = 0;
void dfs(int root) {
    visited[root] = true;
    cnt++;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false && e[i][root] == 1) {
            dfs(i);
        }
    }
    return;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%d:", &K);
        for (int j = 0; j < K; j++) {
            cin >> id;
            for (int c : s[id]) {
                e[c][i] = 1;
                e[i][c] = 1;
            }
            s[id].insert(i);
        }
    }
    fill(visited, visited + N, false);
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            cnt = 0;
            dfs(i);
            res.push_back(cnt);
        }
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
        if (i != 0) cout << " ";
    }
    return 0;
}