#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
bool row[1010];
int v[1010];
int K, N;
int main() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> N;
        bool flag = true;
        int pre = -1;
        fill(row + 1, row + N + 1, false);
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;
            v[j] = num;
            if (row[num] == true) flag = false;
            if (num - pre == 1 || num - pre == -1) flag = false;
            // 对角的判断1
            for (int k = 1; k < j; k++) {
                int x1 = k;
                int y1 = v[x1];
                int x2 = j;
                int y2 = num;
                if (y2 - y1 == x2 - x1) flag = false;
            }
            row[num] = true;
            pre = num;
        }
        if (flag == false)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}