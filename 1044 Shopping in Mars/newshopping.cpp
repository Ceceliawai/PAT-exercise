#include <math.h>

#include <iostream>
#include <map>

using namespace std;

long long int ant[100001];
long long int cur = 0;
map<int, int> res1;  // left + right
map<int, int> res2;  // left+right minsub
int N, M;
int minsub = 1001;

int main() {
    cin >> N >> M;
    ant[0] = 0;
    // 存储累加到当前钻石的总价
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        cur += num;
        ant[i] = cur;
    }

    for (int i = 1; i <= N; i++) {
        int left = 0;
        int right = i - 1;
        int m = 0;
        while (left <= right) {
            m = (left + right) / 2;
            if (ant[m] > ant[i] - M)
                right = m - 1;
            else if (ant[m] < ant[i] - M)
                left = m + 1;
            else if (ant[m] == ant[i] - M)
                break;
        }
        if (ant[i] - ant[m] == M) {  // 找到恰好的m出来的
            res1.insert(make_pair(m + 1, i));
        } else {  // 找到left>right的情况，ant[right]小于目标值，ant[left]大于目标值
            m = max(0, left - 1);
            // 我们要找价格大于M的，取小于目标值的那个，但不能小于0
            if (ant[i] - ant[m] - M > 0 && ant[i] - ant[m] - M < minsub) {
                res2.clear();
                res2.insert(make_pair(m + 1, i));
                minsub = ant[i] - ant[m] - M;
            } else if (ant[i] - ant[m] - M > 0 && ant[i] - ant[m] - M == minsub)
                res2.insert(make_pair(m + 1, i));
        }
    }

    if (res1.size() != 0) {
        for (auto it = res1.begin(); it != res1.end(); it++) {
            cout << it->first;
            cout << "-";
            cout << it->second;
            cout << endl;
        }
    } else {
        for (auto it = res2.begin(); it != res2.end(); it++) {
            cout << it->first;
            cout << "-";
            cout << it->second;
            cout << endl;
        }
    }
    return 0;
}