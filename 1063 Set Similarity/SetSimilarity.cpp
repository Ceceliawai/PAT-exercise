#include <stdio.h>

#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> alls[51];
vector<double> res;
double cal(int a, int b) {
    // 之前是重新插入一个集合然后用size
    // 修改成这样，如果a的元素在b中找到了，说明nc++。如果没找到，说明nt++
    // 好聪明的算法
    int nc = 0;
    int nt = alls[b].size();
    for (int c : alls[a]) {
        if (alls[b].find(c) != alls[b].end()) {
            nc++;
        } else
            nt++;
    }
    double p = nc * 1.0 / nt;
    return p;
}
int main() {
    int N, K, val;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> val;
            alls[i].insert(val);
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        double p = cal(a, b);
        res.push_back(p * 100);
    }
    for (int i = 0; i < res.size(); i++) {
        printf("%.1f%%\n", res[i]);
    }
    return 0;
}