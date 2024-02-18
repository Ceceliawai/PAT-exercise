/**
 * @file newHead.cpp
 * @brief 准备按照图的方式再来写一遍
 * @date 2024-02-18
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define MAXN 2000

using namespace std;

bool e[MAXN][MAXN];     // 顶点之间的边是否存在
int w[MAXN];            // 每个顶点的权重总数
int v[MAXN];            // 每个顶点属于的连通分量编号
bool visited[MAXN];     // dfs时使用
map<int, string> iton;  // index 映射到 string
map<string, int> ntoi;  // string 映射到 index
int comcount = 0;       // 连通分量个数
int cnt = 0;            // 顶点个数

int maxw = 0;      // 当前连通分量最大的权重数
int maxin = -1;    // 当前head的index
int setcount = 0;  // 当前gang的人数
int total = 0;     // 通话时长总数

int N, K;

typedef struct Gang {
    string name;
    int count;
} gang;

vector<gang> res;

void dfs(int root) {
    visited[root] = true;
    v[root] = comcount;
    if (w[root] > maxw) {
        maxw = w[root];
        maxin = root;
    }
    total += w[root];
    setcount++;
    for (int i = 0; i < N; i++) {
        if (visited[i] == false && e[root][i] == true) {
            dfs(i);
        }
    }
}

bool cmp(gang g1, gang g2) { return g1.name < g2.name; }

int main() {
    cin >> N >> K;

    // initial
    fill(e[0], e[0] + MAXN * MAXN, false);
    fill(w, w + MAXN, 0);
    fill(v, v + MAXN, -1);
    fill(visited, visited + MAXN, false);

    for (int i = 0; i < N; i++) {
        string a, b;
        int k;
        cin >> a >> b >> k;
        if (ntoi.count(a) == 0) {
            ntoi.insert(make_pair(a, cnt));
            iton.insert(make_pair(cnt, a));
            cnt++;
        }
        if (ntoi.count(b) == 0) {
            ntoi.insert(make_pair(b, cnt));
            iton.insert(make_pair(cnt, b));
            cnt++;
        }

        int ai = ntoi[a];
        int bi = ntoi[b];
        e[ai][bi] = true;
        e[bi][ai] = true;
        w[ai] += k;
        w[bi] += k;
    }

    // dfs
    for (int i = 0; i < N; i++) {
        int k = -1;
        for (int j = 0; j < N; j++) {
            if (visited[j] == false) {
                k = j;
                break;
            }
        }

        if (k == -1) break;

        // initial
        maxw = 0;      // 当前连通分量最大的权重数
        maxin = -1;    // 当前head的index
        setcount = 0;  // 当前gang的人数
        total = 0;     // 通话时长总数
        dfs(k);
        comcount++;

        if (total / 2 > K && setcount > 2) {
            string name = iton[maxin];
            gang g;
            g.name = name;
            g.count = setcount;
            res.push_back(g);
        }
    }

    sort(res.begin(), res.end(), cmp);

    cout << res.size() << endl;
    if (res.size() == 0) return 0;

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].name;
        cout << " ";
        cout << res[i].count;
        cout << endl;
    }
    return 0;
}