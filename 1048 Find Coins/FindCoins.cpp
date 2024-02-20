#include <algorithm>
#include <iostream>
using namespace std;
int coins[100010];
int N, M, l, r, m, flag = 0;
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + N);
    for (int i = 0; i < N && coins[i] < M; i++) {
        l = i + 1;
        r = N - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (coins[m] == M - coins[i])
                break;
            else if (coins[m] > M - coins[i])
                r = m - 1;
            else
                l = m + 1;
        }
        if (coins[m] == M - coins[i]) {
            cout << coins[i] << " " << coins[m];
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}