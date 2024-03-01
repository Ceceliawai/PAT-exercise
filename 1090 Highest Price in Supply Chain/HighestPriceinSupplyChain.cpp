#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100010];
double P, r;
double maxp = 0;
int maxc = 0;
int N;
void dfs(int root, double p) {
    double curp = root == 0 ? p : p * (1 + r);
    if (v[root].size() == 0) {
        if (p > maxp) {
            maxp = p;
            maxc = 1;
        } else if (p == maxp)
            maxc++;
        return;
    }
    for (int i = 0; i < v[root].size(); i++) {
        dfs(v[root][i], curp);
    }
    return;
}
int main() {
    cin >> N >> P >> r;
    r = r / 100;
    for (int i = 1; i <= N; i++) {
        int pre;
        cin >> pre;
        // index=编号+1
        // 编号=index-1
        v[pre + 1].push_back(i);
    }
    dfs(0, P);
    printf("%.2f %d", maxp, maxc);
    return 0;
}