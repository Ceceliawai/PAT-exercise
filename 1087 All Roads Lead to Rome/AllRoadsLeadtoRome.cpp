#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> toindex;
map<int, string> tostring;
vector<int> pre[210];  // 最短路前驱
vector<int> temp;      // 存当前路径
vector<int> res;       // 存当前快乐最多的哪条路径
int cnt = 0;           // 最短路的个数
int maxh = -1;         // 快乐最多的值
int curh = 0;          // 当前路径的快乐的值
int e[210][210], d[210], w[210], N, K;
bool visited[210];
int INF = (0x1) << 30;
void dfs(int root) {
    temp.push_back(root);
    curh += w[root];
    if (root == 0) {
        cnt++;
        if (curh > maxh) {
            maxh = curh;
            res = temp;
        }
        temp.pop_back();
        curh -= w[root];
        return;
    }
    for (int i = 0; i < pre[root].size(); i++) {
        dfs(pre[root][i]);
    }
    temp.pop_back();
    curh -= w[root];
    return;
}
int main() {
    fill(e[0], e[0] + 210 * 210, INF);
    fill(d, d + 210, INF);
    fill(visited, visited + 210, false);
    cin >> N >> K;
    string name;
    int val;
    cin >> name;
    toindex[name] = 0;
    tostring[0] = name;
    w[0] = 0;
    for (int i = 1; i <= N - 1; i++) {
        cin >> name >> val;
        toindex[name] = i;
        tostring[i] = name;
        w[i] = val;
    }
    for (int i = 0; i < K; i++) {
        string a, b;
        cin >> a >> b >> val;
        int ai = toindex[a];
        int bi = toindex[b];
        e[ai][bi] = val;
        e[bi][ai] = val;
    }

    // dijkstra
    d[0] = 0;
    for (int k = 0; k < N; k++) {
        int u = -1;
        int mind = INF;
        for (int i = 0; i < N; i++) {
            if (visited[i] == false && d[i] < mind) {
                u = i;
                mind = d[i];
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int i = 0; i < N; i++) {
            if (e[u][i] != INF && d[i] > d[u] + e[u][i]) {
                pre[i].clear();
                pre[i].push_back(u);
                d[i] = d[u] + e[u][i];
            } else if (e[u][i] != INF && d[i] == d[u] + e[u][i]) {
                pre[i].push_back(u);
            }
        }
    }
    dfs(toindex["ROM"]);  // 从终点开始向前溯源
    cout << cnt << " " << d[toindex["ROM"]] << " " << maxh << " "
         << maxh / (res.size() - 1) << endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << tostring[res[i]];
        if (i != 0) cout << "->";
    }
    return 0;
}