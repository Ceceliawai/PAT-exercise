#include <algorithm>
#include <iostream>
using namespace std;
int start[100010], n, q, page;  // 第n章的开始页码
int findpart(int num) {
    int l = 0;
    int r = n - 1;
    int m;
    while (l <= r) {
        m = (l + r) / 2;
        if (start[m] > num)
            r = m - 1;
        else if (start[m] < num)
            l = m + 1;
        else
            break;
    }
    if (start[m] == num) return m;
    return max(0, r);
}
int main() {
    cin >> n >> q;
    start[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> page;
        page = max(2, page);
        page = min(page, 1000000000);
        start[i] = page;
    }
    for (int i = 0; i < q; i++) {
        cin >> page;
        cout << findpart(page) + 1 << endl;
    }
    return 0;
}