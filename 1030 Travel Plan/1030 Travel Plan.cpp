#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF 9999999

int e[500][500];       // the length of every edge
int c[500][500];       // the cost of ever edge
int d[500];            // distance
vector<int> pre[500];  // the pre city in the shortest path
bool visited[500];     // mark the visited city
int N, M, S, D;
int cost = INF;  // the min cost;
int tempc = 0;
vector<int> path;  // result path
vector<int> temp;  // now path

void dfs(int root) {
	int a=0;
	int val=0;
	if(temp.size() != 0){
		a = temp[temp.size() - 1];
    	val = c[a][root];
	}
    tempc += val;
    temp.push_back(root);
    if (root == S) {
        //int a = temp[temp.size() - 2];
        if (tempc < cost) {
            cost = tempc;
            path = temp;
        }
        temp.pop_back();
        tempc -= val;
        return;
    }

    for (int i = 0; i < pre[root].size(); i++) {
        if (count(temp.begin(), temp.end(), pre[root][i]) == 0) {
            dfs(pre[root][i]);
        }
    }

    temp.pop_back();
    tempc -= val;
    return;
}

int main() {
    cin >> N >> M >> S >> D;

    fill(e[0], e[0] + 250000, INF);
    fill(c[0], c[0] + 250000, INF);
    fill(visited, visited + 500, false);
    fill(d, d + 500, INF);

    for (int m = 0; m < M; m++) {
        int i, j, l, w;
        cin >> i >> j >> l >> w;
        e[i][j] = e[j][i] = l;
        c[i][j] = c[j][i] = w;
    }

    // dijkstra
    d[S] = 0;
    for (int i = 0; i < N; i++) {
        int min = INF;
        int u = -1;
        for (int i = 0; i < N; i++) {
            if (visited[i] == false && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        if (u == -1) break;

        visited[u] = true;

        for (int i = 0; i < N; i++) {
            if (e[u][i] != INF && d[i] > d[u] + e[u][i]) {
                pre[i].clear();
                pre[i].push_back(u);
                d[i] = d[u] + e[u][i];
            } else if (e[u][i] != INF && d[i] == d[u] + e[u][i])
                pre[i].push_back(u);
        }
    }

    // fill(visited, visited + 500, false);
    dfs(D);  // 反向dfs

    for (int i = path.size() -1 ; i >= 0; i--) {
        cout << path[i];
        cout << " ";
    }
    cout << d[D];
    cout << " ";
    cout << cost;

    return 0;
}
