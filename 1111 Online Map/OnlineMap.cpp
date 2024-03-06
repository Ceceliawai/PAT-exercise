#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> dpre[510];
vector<int> tpre[510];
int e[510][510], t[510][510], d[510], dt[510], v1, v2, oneway, dis, tim;
vector<int> temp;
vector<int> res1;
int curd, curt;
int INF = (0x1) << 30;
int res1t = INF;
int res2d = INF;
vector<int> res2;
bool visited[510];
int N, M;
int Start, Dest;
bool isEqual() {
    for (int i = 0; i < res1.size() && i < res2.size(); i++) {
        if (res1[i] != res2[i]) return false;
    }
    return true;
}
void dfs1(int root) {
    temp.push_back(root);
    if (root == Start) {
        // 找到了一条路径
        if (curt < res1t) {
            res1 = temp;
            res1t = curt;
            temp.pop_back();
            return;
        }
    }
    for (int i = 0; i < dpre[root].size(); i++) {
        curt += t[dpre[root][i]][root];
        dfs1(dpre[root][i]);
        curt -= t[dpre[root][i]][root];
    }
    temp.pop_back();
    return;
}
void dfs2(int root) {
    temp.push_back(root);
    if (root == Start) {
        // 找到了一条路径
        if (res2.size() == 0 || temp.size() < res2.size()) {
            res2 = temp;
            res2d = curd;
            temp.pop_back();
            return;
        }
    }
    for (int i = 0; i < tpre[root].size(); i++) {
        dfs2(tpre[root][i]);
    }
    temp.pop_back();
    return;
}
int main() {
    fill(e[0], e[0] + 510 * 510, INF);
    fill(t[0], t[0] + 510 * 510, INF);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2 >> oneway >> dis >> tim;
        if (oneway == 1) {
            // 单向的路
            e[v1][v2] = dis;
            t[v1][v2] = tim;
        } else {
            e[v1][v2] = dis;
            t[v1][v2] = tim;
            e[v2][v1] = dis;
            t[v2][v1] = tim;
        }
    }
    cin >> Start >> Dest;
    // 第一次dijkstra 按照distance
    fill(d, d + 510, INF);
    fill(visited, visited + 510, false);
    d[Start] = 0;
    for (int i = 0; i < N; i++) {
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
                d[i] = d[u] + e[u][i];
                dpre[i].clear();
                dpre[i].push_back(u);
            } else if (e[u][i] != INF && d[i] == d[u] + e[u][i]) {
                dpre[i].push_back(u);
            }
        }
    }
    // 反向遍历，找到最短路径
    dfs1(Dest);

    fill(dt, dt + 510, INF);
    fill(visited, visited + 510, false);
    dt[Start] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1;
        int mind = INF;
        for (int i = 0; i < N; i++) {
            if (visited[i] == false && dt[i] < mind) {
                u = i;
                mind = d[i];
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int i = 0; i < N; i++) {
            if (t[u][i] != INF && dt[i] > dt[u] + t[u][i]) {
                dt[i] = dt[u] + t[u][i];
                tpre[i].clear();
                tpre[i].push_back(u);
            } else if (t[u][i] != INF && dt[i] == dt[u] + t[u][i]) {
                tpre[i].push_back(u);
            }
        }
    }
    // 反向遍历，找到最短路径
    dfs2(Dest);

    bool flag = isEqual();

    if (flag == true) {
        cout << "Distance = " << d[Dest] << "; Time = " << dt[Dest] << ": ";
        for (int i = res1.size() - 1; i >= 0; i--) {
            cout << res1[i];
            if (i != 0) cout << " -> ";
        }
    } else {
        cout << "Distance = " << d[Dest] << ": ";
        for (int i = res1.size() - 1; i >= 0; i--) {
            cout << res1[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
        cout << "Time = " << dt[Dest] << ": ";
        for (int i = res2.size() - 1; i >= 0; i--) {
            cout << res2[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }
    return 0;
}