#include <math.h>

#include <algorithm>
#include <iostream>

using namespace std;

#define INF 99999999

int price[100001];
int N, M;
int minsub = INF;
int cleft[100001];
int cright[100001];
int minleft[100001];
int minright[100001];
int cnt = 0;
int mnt = 0;

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    int val = 0;
    for (int i = 1; i <= N; i++) {
        val = 0;
        int j;
        for (j = i; j <= N; j++) {
            val += price[j];
            if (val >= M) break;
        }
        if (j > N) j = N;
        if (val - M > 0 && val - M < minsub) {
            minsub = val - M;
            mnt = 0;
            minleft[mnt] = i;
            minright[mnt] = j;
            mnt++;
        } else if (val - M > 0 && val - M == minsub) {
            minleft[mnt] = i;
            minright[mnt] = j;
            mnt++;
        } else if (val == M) {
            cleft[cnt] = i;
            cright[cnt] = j;
            cnt++;
        }
    }

    if (cnt == 0) {
        for (int i = 0; i < mnt; i++) {
            cout << minleft[i] << "-" << minright[i] << endl;
        }
    } else {
        for (int i = 0; i < cnt; i++) {
            cout << cleft[i] << "-" << cright[i] << endl;
        }
    }
    return 0;
}
