#include <iostream>

using namespace std;

int post[31];
int in[31];
int nodes[31][31];  // index depth
int count = 0;
int maxdepth = 0;

void BuildTree(int pl, int pr, int il, int ir, int depth) {
  if (pl > pr || il > ir) {
    return;
  }
  if (depth > maxdepth) maxdepth = depth;
  if (pl == pr || il == ir) {
    nodes[count][0] = post[pl];
    nodes[count][1] = depth;
    count++;
    return;
  }
  int root = post[pr];
  int i;  // index
  for (i = il; i <= ir; i++) {
    if (in[i] == root) break;
  }
  nodes[count][0] = root;
  nodes[count][1] = depth;
  count++;
  int length = i - il;
  BuildTree(pl, pl + length - 1, il, i - 1, depth + 1);
  BuildTree(pl + length, pr - 1, i + 1, ir, depth + 1);
  return;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> post[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> in[i];
  }
  BuildTree(0, N - 1, 0, N - 1, 0);
  int n = 0;
  for (int i = 0; i <= maxdepth; i++) {
    for (int j = 0; j < N; j++) {
      if (nodes[j][1] == i) {
        if (n != 0) cout << " ";
        cout << nodes[j][0];
        n++;
      }
    }
  }
  return 0;
}
