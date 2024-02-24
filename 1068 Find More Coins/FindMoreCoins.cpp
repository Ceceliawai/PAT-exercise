#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int coins[10010], N, M, total = 0;
vector<int> temp;
vector<int> res;
bool Find(int i) {
    temp.push_back(coins[i]);
    total += coins[i];
    if (total == M) {
        res = temp;
        return true;
    }
    if (total > M) {
        temp.pop_back();
        total -= coins[i];
        return false;
    }
    for (int j = i + 1; j < N && total + coins[j] <= M; j++) {
        if (Find(j) == true) return true;
    }
    total -= coins[i];
    temp.pop_back();
    return false;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + N);
    bool flag = false;
    for (int i = 0; i < N; i++) {
        flag = Find(i);
        if (flag == true) break;
    }
    if (flag == false) {
        cout << "No Solution";
        return 0;
    } else {
        for (int i = 0; i < res.size(); i++) {
            if (i != 0) cout << " ";
            cout << res[i];
        }
        return 0;
    }
}
