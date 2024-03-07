#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, num;
long long int sum = 0;
vector<int> nums;
long long int fabs(long long a) {
    if (a > 0)
        return a;
    else
        return -a;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        sum += num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    long long cur = 0;
    for (int i = 0; i < N; i++) {
        cur += nums[i];
        if (N % 2 == 0) {
            if (i == N / 2 - 1) {
                cout << "0 ";
                cout << fabs(sum - cur * 2);
                return 0;
            }
        }
        if (N % 2 != 0) {
            if (i == N / 2) {
                cout << "1 ";
                if (fabs(sum - cur - cur) > fabs(sum - (cur - nums[i]) * 2)) {
                    cout << fabs(sum - cur - cur);
                } else {
                    cout << fabs(sum - (cur - nums[i]) * 2);
                }
                return 0;
            }
        }
    }
}