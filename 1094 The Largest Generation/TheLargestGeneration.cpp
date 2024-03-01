#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[110];
vector<int> d[110];  // 记录层数为i的所有结点
int maxd = 1;
void dfs(int root, int depth) {
    maxd = max(depth, maxd);
    if (count(d[depth].begin(), d[depth].end(), root) == 0) {
        d[depth].push_back(root);
    }
    for (int i = 0; i < v[root].size(); i++) {
        dfs(v[root][i], depth + 1);
    }
    return;
}
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int id, k, idk;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> idk;
            v[id].push_back(idk);
        }
    }
    dfs(1, 1);
    int md, mc;
    md = 1;
    mc = 1;
    for (int i = 2; i <= maxd; i++) {
        if (d[i].size() > mc) {
            mc = d[i].size();
            md = i;
        }
    }
    cout << mc << " " << md;
    return 0;
}