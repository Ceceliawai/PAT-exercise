#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int N, Q, dnt = 0;
int maxcnt = 0;
int cnt = 0;
vector<int> v[10010];
set<int> birds;
bool visited[10010];
int d[10010];
void dfs(int root) {
    visited[root] = true;
    d[root] = dnt;
    cnt++;
    for (int i = 0; i < v[root].size(); i++) {
        if (visited[v[root][i]] == false) {
            dfs(v[root][i]);
        }
    }
    return;
}
int main() {
    cin >> N;
    fill(visited, visited + 10010, false);
    fill(d, d + 10010, -1);
    for (int i = 0; i < N; i++) {
        int K, id;
        cin >> K;
        set<int> s;
        for (int j = 0; j < K; j++) {
            cin >> id;
            for (int c : s) {
                v[c].push_back(id);
                v[id].push_back(c);
            }
            s.insert(id);
            birds.insert(id);
        }
    }

    for (int c : birds) {
        if (visited[c] == false) {
            dnt++;
            cnt = 0;
            dfs(c);
            maxcnt = max(cnt, maxcnt);
        }
    }
    cout << dnt << " " << birds.size() << endl;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        if (d[x] != d[y])
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}