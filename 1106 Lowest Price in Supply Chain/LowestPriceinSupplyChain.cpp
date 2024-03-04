#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> v[100010];
int d[100010], N, K, id;
double P, r;
int main() {
    cin >> N >> P >> r;
    r = r / 100.0;
    for (int i = 0; i < N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> id;
            v[i].push_back(id);
        }
    }
    queue<int> q;
    q.push(0);
    d[0] = 0;
    double minp = pow(10, 10) + 1;
    int cnt = 0;
    while (q.empty() == false) {
        int root = q.front();
        q.pop();
        if (v[root].size() != 0) {
            int curd = d[root] + 1;
            for (int i = 0; i < v[root].size(); i++) {
                q.push(v[root][i]);
                d[v[root][i]] = curd;
            }
        } else {
            if (P * pow(1 + r, d[root]) < minp) {
                minp = P * pow(1 + r, d[root]);
                cnt = 1;
            } else if (P * pow(1 + r, d[root]) == minp)
                cnt++;
        }
    }
    printf("%.4f %d", minp, cnt);
    return 0;
}