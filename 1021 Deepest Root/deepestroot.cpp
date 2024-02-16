#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> nodes[10001];  // used to record the adjacent nodes
bool visited[10001];
int N;
int nodecount = 0;
int maxd = -1;
set<int> s;
vector<int> temp;

void dfs(int root, int depth) {
    visited[root] = true;
    nodecount++;
    if (depth > maxd) {
        temp.clear();
        temp.push_back(root);
        maxd = depth;
    } else if (depth == maxd) {
        temp.push_back(root);
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false &&
            count(nodes[root].begin(), nodes[root].end(), i) != 0) {
            dfs(i, depth + 1);
        }
    }
    return;
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
        dfs(i, 0);  // the depth of the root of a tree is 0
        count++;
    }

    // not a tree
    if (count != 1) {
        cout << "Error: " << count << " components";
        return 0;
    }

    int s1 = temp[0];
    for (int i = 0; i < temp.size(); i++) {
        s.insert(temp[i]);
    }
    temp.clear();
    fill(visited, visited + 10001, false);
    dfs(s1, 0);
    for (int i = 0; i < temp.size(); i++) {
        s.insert(temp[i]);
    }
    for (int c : s) {
        cout << c << endl;
    }

    return 0;
}