#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10010;
const int maxm = 110;
const int INF = (1 << 30) - 1;
int dp[maxn][maxm];
int w[maxn];
bool choice[maxn][maxm] = {false};
bool cmp(int a, int b) { return a > b; }
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1);
    memset(dp[0], 0, sizeof(dp[0]));
    bool flag = false;
    // 01背包循环代码主体，本题中体积和价值一样
    for (int i = 1; i <= n; i++) {
        for (int v = m; v >= w[i]; v--) {
            if (dp[i - 1][v] > dp[i - 1][v - w[i]] + w[i]) {
                dp[i][v] = dp[i - 1][v];
                choice[i][v] = false;
            } else {
                dp[i][v] = dp[i - 1][v - w[i]] + w[i];
                choice[i][v] = true;
            }
        }
        if (dp[i][m] == m) {
            flag = true;
        }
    }
    if (flag == false) {
        printf("No Solution\n");
    } else {
        int cnt = 0;
        // 因为是从大到小排的，所以从后面开始遍历
        for (int i = n; i > 0; i--) {
            if (choice[i][m] == true) {
                if (cnt != 0) {
                    printf(" ");
                }
                m = m - w[i];  // 更新当前剩余价值
                printf("%d", w[i]);
                cnt++;
            }
        }
    }

    return 0;
}
