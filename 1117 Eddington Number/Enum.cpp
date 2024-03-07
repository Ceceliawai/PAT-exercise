#include <algorithm>
#include <iostream>
using namespace std;
int N;
int days[100010];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }
    sort(days, days + N);
    int curd = days[N - 1];  // 当前的更大的miles
    int lastd;
    int cnt = 0;     // 当前的比curd更大的天数
    int curcnt = 1;  // 骑行等于curd的天数
    for (int i = N - 2; i >= 0; i--) {
        int E = N - i - 1;
        if (days[i] == curd) {
            curcnt++;
        } else {
            lastd = curd;
            curd = days[i];
            cnt += curcnt;
            curcnt = 1;
        }
        // 比curd更大的天数有curd天
        if (curd == cnt) {
            cout << cnt;
            return 0;
        }
        if (curd < cnt && lastd > cnt) {
            cout << cnt;
        }
    }
}