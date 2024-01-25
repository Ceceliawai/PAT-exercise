// 连通分量问题，去掉一个顶点之后计算有几个连通分量
#include <iostream>
using namespace std;

bool visited[1002];    // 已访问
bool adj[1002][1002];  // 顶点之间的边是否存在
// int count;//连通分量个数

void BFS(int cur, int n, int note) {
  visited[cur] = true;
  for (int i = 1; i <= n; i++) {
    if (i != note && adj[cur][i] == true && visited[i] == false) {
      BFS(i, n, note);
    }
  }
  return;
}

void initv(int n) {
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  return;
}

void initadj() {
  for (int i = 0; i < 1002; i++) {
    for (int j = 0; j < 1002; j++) {
      adj[i][j] = false;
    }
  }
  return;
}

void calcu(int note, int n) {
  initv(n);       // 初始化visit数组
  int count = 0;  // 连通分量个数
  for (int i = 1; i <= n; i++) {
    if (i != note && visited[i] == false) {
      BFS(i, n, note);
      count++;
    }
  }
  cout << count - 1
       << endl;  // 只有一个连通分量的话就不用补，所以要补的是连通分量-1条路
  return;
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  initadj();
  for (int i = 0; i < M; i++) {  // 处理图的关系
    int a, b;
    cin >> a >> b;
    adj[a][b] = true;
    adj[b][a] = true;
  }
  for (int i = 0; i < K; i++) {
    int note;
    cin >> note;
    calcu(note, N);
  }
  return 0;
}