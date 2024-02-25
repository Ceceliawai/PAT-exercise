#include <algorithm>
#include <iostream>
using namespace std;
int coins[10010], dp[10010][110], N, M;
bool choice[110][110];
bool mycmp(int a, int b) { return a > b; }
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> coins[i];
    sort(coins, coins + N, mycmp);
    fill(dp[0], dp[0] + 10010 * 110, 0);
    bool flag = false;
    for (int j = coins[0]; j <= M; j++) {
        dp[0][j] = coins[0];
        choice[0][j] = true;
        if (dp[0][M] == M) flag = true;
    }
    for (int i = 1; i < N; i++) {
        for (int j = coins[i]; j <= M; j++) {
            int x = dp[i - 1][j];
            int y = dp[i - 1][j - coins[i]] + coins[i];
            if (x > y) {
                choice[i][j] = false;
                dp[i][j] = x;
            } else {
                choice[i][j] = true;
                dp[i][j] = y;
            }
        }
        if (dp[i][M] == M) flag = true;
    }
    if (flag == false) {
        cout << "No Solution";
    } else {
        int cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (choice[i][M] == true) {
                if (cnt != 0) cout << " ";
                cout << coins[i];
                cnt++;
                M = M - coins[i];
            }
        }
    }
    return 0;
}