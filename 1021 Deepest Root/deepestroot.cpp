#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes[10001];  // used to record the adjacent nodes
bool visited[10001];
int d[10001];
int N;
int nodecount = 0;

bool TestTree() {
  for (int i = 1; i <= N; i++) {
    if (visited[i] == false) return false;
  }
  return true;
}

int dfs(int root, int depth, bool flag) {
  visited[root] = true;
  nodecount++;
  if (flag == true) d[root] = depth;
  int maxd = depth;
  for (int i = 1; i <= N; i++) {
    if (visited[i] == false &&
        count(nodes[root].begin(), nodes[root].end(), i) != 0) {
      int temp = dfs(i, depth + 1, flag);
      if (temp > maxd) maxd = temp;
    }
  }
  return maxd;
}

int main() {
  cin >> N;
  fill(visited, visited + 10001, false);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }

  int count = 0;
  nodecount = 0;
  while (nodecount != N) {
    int i;
    for (i = 1; i <= N; i++) {
      if (visited[i] == false) break;
    }
    dfs(i, 0, true);  // the depth of the root of a tree is 0
    count++;
  }

  // not a tree
  if (count != 1) {
    cout << "Error: " << count << " components";
    return 0;
  }

  vector<int> res;
  res.clear();
  int treed = -1;
  for (int i = 1; i <= N; i++) {
    if (nodes[i].size() == 1) {  // leaf node
      if (N < 500) fill(visited + 1, visited + 1 + N, false);
      int temp = dfs(i, 0, false);
      if (temp > treed) {
        treed = temp;
        res.clear();
        res.push_back(i);
      } else if (temp == treed) {
        res.push_back(i);
      }
    }
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}