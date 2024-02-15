/*
标准算法：dijkstra，记录最短路前驱，然后反向dfs
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;
void dfs(int v) {
  temppath.push_back(v);
  if (v == 0) {
    int need = 0, back = 0;
    for (int i = temppath.size() - 1; i >= 0;
         i--) {  // temppath是反向的路径，所以从后面开始
      int id = temppath[i];
      if (weight[id] > 0) {
        back += weight[id];
      } else {
        if (back > (0 - weight[id])) {
          back += weight[id];
        } else {
          need += ((0 - weight[id]) - back);
          back = 0;
        }
      }
    }
    if (need < minNeed) {
      minNeed = need;
      minBack = back;
      path = temppath;
    } else if (need == minNeed && back < minBack) {  // take相同选back更小的
      minBack = back;
      path = temppath;
    }
    temppath.pop_back();  // 把刚push进去的顶点弹出去，维持当前节点不变
    return;
  }
  for (int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);  // 去找先驱
  temppath.pop_back();
}
int main() {
  fill(e[0], e[0] + 510 * 510, inf);
  fill(dis, dis + 510, inf);
  scanf("%d%d%d%d", &cmax, &n, &sp, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &weight[i]);
    weight[i] = weight[i] - cmax / 2;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    scanf("%d", &e[a][b]);
    e[b][a] = e[a][b];
  }
  // dijkstra的经典算法，要熟练
  dis[0] = 0;
  for (int i = 0; i <= n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j <= n; j++) {
      if (visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if (u == -1) break;
    visit[u] = true;
    for (int v = 0; v <= n; v++) {
      if (visit[v] == false && e[u][v] != inf) {
        if (dis[v] > dis[u] + e[u][v]) {
          dis[v] = dis[u] + e[u][v];
          pre[v].clear();       // 之前的pre都不算数了
          pre[v].push_back(u);  // 压入新的
        } else if (dis[v] == dis[u] + e[u][v]) {
          pre[v].push_back(u);  // 更当前dist一样，压入新的
        }
      }
    }
  }
  dfs(sp);  // 反向dfs
  printf("%d 0", minNeed);
  for (int i = path.size() - 2; i >= 0; i--) printf("->%d", path[i]);
  printf(" %d", minBack);
  return 0;
}