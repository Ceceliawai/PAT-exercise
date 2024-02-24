#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[1010];
int val[1010], N, d[1010], maxd = -1;
void build(int l, int r, int curd) {
    maxd = max(curd, maxd);
    int tsize = r - l + 1;
    if (tsize <= 0) return;
    if (tsize == 1) {
        tree[curd].push_back(val[l]);
        // d[l] = curd;
        return;
    }
    int csize = 0;
    int i = 0;  // 树高
    for (i = 0; (int)pow(2, i) - 1 < tsize; i++) {
        csize = (int)pow(2, i) - 1;
    }
    int remain = tsize - csize;
    i--;
    int index;
    if (remain > pow(2, i - 1)) {
        index = l + (int)pow(2, i) - 1;
    } else {
        index = l + remain + (int)pow(2, i - 1) - 1;
    }
    tree[curd].push_back(val[index]);
    // d[index] = curd;
    build(l, index - 1, curd + 1);  // 左边
    build(index + 1, r, curd + 1);  // 右边
    return;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    sort(val, val + N);
    build(0, N - 1, 1);
    // for (int i = 1; i <= maxd; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (d[j] == i) {
    //             if (flag == true) cout << " ";
    //             cout << j;
    //             flag = true;
    //         }
    //     }
    // }
    bool flag = false;
    for (int i = 1; i <= maxd; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if (flag == true) cout << " ";
            cout << val[tree[i][j]];
            flag = true;
        }
    }
    return 0;
}