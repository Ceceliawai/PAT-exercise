#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int v[110][2];  // 0 for left and 1 for right
int N, l, r, cnt = 0;
int key[110], mdata[110];
queue<int> q;
void inorder(int root) {
    if (root == -1) return;
    inorder(v[root][0]);
    mdata[root] = key[cnt];
    cnt++;
    inorder(v[root][1]);
    return;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        v[i][0] = l;
        v[i][1] = r;
    }
    for (int i = 0; i < N; i++) {
        cin >> key[i];
    }
    sort(key, key + N);
    inorder(0);  // 维护所有的节点的值
    // 层次遍历
    q.push(0);
    int cur;
    while (q.empty() != false) {
        cur = q.front();
        if (cur != 0) cout << " ";
        cout << mdata[cur];
        q.pop();
        if (v[cur][0] != -1) q.push(v[cur][0]);
        if (v[cur][1] != -1) q.push(v[cur][1]);
    }
    return 0;
}