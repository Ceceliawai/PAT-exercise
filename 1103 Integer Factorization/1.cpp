#include <math.h>
// 5和6超时
// 添加lastf之后只有5超时
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, K, P;
vector<int> temp;
int cnt = 0;
int maxcnt = -1;
vector<int> res;
void findf(int num, int k, int p, int lastf) {
    if (num == 0 && k == 0) {
        if (cnt > maxcnt) {
            maxcnt = cnt;
            res = temp;
        }
        return;
    }
    if (num <= 0 || k == 0) return;
    int i = pow(num - k + 1, 1.0 / p) + 1;
    // 不能比上次的更大
    i = min(i, lastf);
    for (; i >= 1; i--) {
        temp.push_back(i);
        cnt += i;
        findf(num - pow(i, p), k - 1, p, i);
        temp.pop_back();
        cnt -= i;
    }
    return;
}

int main() {
    cin >> N >> K >> P;
    findf(N, K, P, (0x1) << 30);
    if (res.size() == 0)
        cout << "Impossible";
    else {
        cout << N;
        cout << " =";
        for (int i = 0; i < res.size(); i++) {
            if (i != 0) cout << " +";
            cout << " ";
            cout << res[i];
            cout << "^";
            cout << P;
        }
    }
    return 0;
}