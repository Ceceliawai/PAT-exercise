#include <string.h>

#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
int v[11][2];
int N, cnt = 0;
set<int> ms;
void inorder(int root) {
    if (root == -1) return;
    inorder(v[root][1]);
    if (cnt != 0) cout << " ";
    cout << root;
    cnt++;
    inorder(v[root][0]);
    return;
}
int main() {
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s != "-") {
            v[i][0] = stoi(s);
            ms.insert(v[i][0]);
        } else
            v[i][0] = -1;
        cin >> s;
        if (s != "-") {
            v[i][1] = stoi(s);
            ms.insert(v[i][1]);
        } else
            v[i][1] = -1;
    }
    // level-order
    // 注意本题是从右向左输出就行
    queue<int> q;
    int root;
    for (int i = 0; i < N; i++) {
        if (ms.count(i) == 0) {
            root = i;
            break;
        }
    }
    q.push(root);
    while (q.empty() == false) {
        int cur = q.front();
        q.pop();  // 少了这个运行超时
        if (cnt != 0) cout << " ";
        cout << cur;
        cnt++;
        if (v[cur][1] != -1) q.push(v[cur][1]);
        if (v[cur][0] != -1) q.push(v[cur][0]);
    }
    cout << endl;
    cnt = 0;
    inorder(root);
    return 0;
}