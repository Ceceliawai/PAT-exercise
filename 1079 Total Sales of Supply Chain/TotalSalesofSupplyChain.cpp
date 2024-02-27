#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> n[100010];
int numofpro[100010];
int N, K, curid;
double P, r, total = 0;
void dfs(int root, double curp) {
    double newp = root != 0 ? curp * (1 + r) : curp;
    if (n[root].size() == 0) {
        total += newp * numofpro[root];
        return;
    } else {
        for (int i = 0; i < n[root].size(); i++) {
            dfs(n[root][i], newp);
        }
    }
    return;
}
int main() {
    cin >> N >> P >> r;
    r = r / 100;  // 转换成百分数
    fill(numofpro, numofpro + 100010, 0);
    for (int i = 0; i < N; i++) {
        cin >> K;
        if (K != 0) {
            for (int j = 0; j < K; j++) {
                cin >> curid;
                n[i].push_back(curid);
            }
        } else {
            cin >> curid;
            numofpro[i] = curid;
        }
    }
    dfs(0, P);
    printf("%.1f", total);
}
