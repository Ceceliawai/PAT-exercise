#include <algorithm>
#include <iostream>
using namespace std;
int d[1010][2];  // 0表示互质的长度 1表示不互质的长度
int num[1010];   // 存所有的数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);  // 利用递归求最大公约数
}
int main() {
    int n;
    cin >> n;
    fill(d[0], d[0] + 1010 * 2, 1);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    d[0][0] = 1;
    d[0][1] = 1;
    int maxd = 1;
    for (int i = 1; i < n; i++) {
        int d1 = 1;  // 0 true
        int d2 = 1;  // 1 false
        for (int j = i - 1; j >= 0 && (i - j + 1 > d1 || i - j + 1 > d2); j--) {
            if (gcd(num[i], num[j]) == 1) {
                d1 = max(d[j][1] + 1, d1);
                // 这一个互质，则上一个和上一个的上一个不互质
            } else {
                d2 = max(d[j][0] + 1, d2);
            }
        }
        d[i][0] = d1;
        maxd = max(maxd, d1);
        d[i][1] = d2;
        maxd = max(maxd, d2);
    }
    cout << maxd;
}