#include <string.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int v[25][2];
bool e[25];
int N;
int main() {
    cin >> N;
    string s;
    fill(e, e + 25, false);
    fill(v[0], v[0] + 25 * 2, -1);
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s != "-") {
            v[i][0] = stoi(s);
            e[stoi(s)] = true;
        }
        cin >> s;
        if (s != "-") {
            v[i][1] = stoi(s);
            e[stoi(s)] = true;
        }
    }
    int root;
    for (int i = 0; i < N; i++) {
        if (e[i] == false) {
            root = i;
            break;
        }
    }
    bool flag = true;
    bool onlyleft = false;
    bool meetnull = false;
    queue<int> q;
    q.push(root);
    int cur;
    int lastnode = root;
    while (q.empty() == false) {
        cur = q.front();
        if (cur != -1) {
            lastnode = cur;
        }
        q.pop();
        if (cur == -1) {
            meetnull = true;
            continue;
        }
        if (meetnull == true && cur != -1) {
            flag = false;
            break;
        }
        if (onlyleft == true) {
            if (v[cur][0] != -1 || v[cur][1] != -1) {
                flag = false;
                break;
            }
        }
        if (v[cur][0] == -1 && v[cur][1] != -1) {
            flag = false;
            break;
        }
        if (v[cur][0] != -1 && v[cur][1] == -1) {
            onlyleft = true;
            // 从这之后的必须是叶子节点
        }
        q.push(v[cur][0]);
        q.push(v[cur][1]);
    }
    if (flag == false) {
        cout << "NO " << root << endl;
    } else {
        cout << "YES ";
        // 层次遍历
        cout << lastnode;
    }
    return 0;
}