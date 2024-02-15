#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int adj[501][501];
int bikes[501];
int capacity, N, pindex, M;
#define INF 999999999
vector<vector<int> > paths;

typedef struct myPath {
  vector<int> p;
  int back;
  int take;
} mypath;

void calpath(int cur, vector<int> p) {
  int min = INF;
  vector<int> cp = p;
  cp.push_back(cur);
  if (cur == pindex) {
    paths.push_back(cp);
    return;
  }
  // 所有可能的路都走一遍
  for (int i = 0; i <= N; i++) {
    if (i != cur && adj[cur][i] != INF) {
      if (count(cp.begin(), cp.end(), i) == 0) {  // 不走回头路
        calpath(i, cp);
      }
    }
  }
  return;
}

bool cmp(mypath p1, mypath p2) {
  if (p1.back != p2.back) return p1.back < p2.back;
  return p1.take < p2.take;
}

int main() {
  fill(adj[0], adj[0] + 501 * 501, INF);  // 初始化
  cin >> capacity >> N >> pindex >> M;
  for (int i = 1; i <= N; i++) {
    cin >> bikes[i];  // 现存的bike数目
  }
  // 路径原始
  for (int k = 0; k < M; k++) {
    int i, j;
    int w;
    cin >> i >> j >> w;
    adj[i][j] = w;
    adj[j][i] = w;
  }

  vector<int> p;
  p.clear();
  calpath(0, p);

  int min = INF;
  int nums = paths.size();
  int w[nums];
  fill(w, w + nums, INF);
  for (int i = 0; i < paths.size(); i++) {
    int sum = 0;
    for (int j = 0; j < paths[i].size() - 1; j++) {
      sum += adj[paths[i][j]][paths[i][j + 1]];
    }
    w[i] = sum;
    if (sum < min) min = sum;
  }
  mypath ps[paths.size()];
  int fabs = INF;
  int count = 0;
  for (int i = 0; i < paths.size(); i++) {
    if (w[i] == min) {
      count++;
      // 开始判断
      int sum = 0;   // 未分配的bikes总数
      int take = 0;  // 需要从PBMC拿出来的个数
      int back = 0;  // 需要拿回去的个数
      for (int j = 0; j < paths[i].size(); j++) {
        if (paths[i][j] != 0) {
          if (bikes[paths[i][j]] < capacity / 2) {
            if ((capacity / 2 - bikes[paths[i][j]]) > sum) {
              take +=
                  capacity / 2 - bikes[paths[i][j]] - sum;  // 拿上差的这些bikes
              sum = 0;  // 现有的不够分的，只剩0个了
            } else {
              sum = sum -
                    (capacity / 2 - bikes[paths[i][j]]);  // 分给当前的这个节点
            }
          } else if (bikes[paths[i][j]] >= capacity / 2) {
            sum += bikes[paths[i][j]] - capacity / 2;  // 可分配的更多了
          }
        }
      }
      back = sum;  // 剩下的未分配的都得拿回去
      mypath p;
      ps[i].p = paths[i];
      ps[i].take = take;
      ps[i].back = back;
    }
  }

  sort(ps, ps + count, cmp);
  mypath res = ps[0];
  cout << res.take;
  cout << ' ';
  for (int i = 0; i < res.p.size(); i++) {
    if (i != 0) cout << "->";
    cout << res.p[i];
  }
  cout << ' ';
  cout << res.back;
  cout << endl;
  return 0;
}
