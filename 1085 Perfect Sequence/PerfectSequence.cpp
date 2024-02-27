#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int N, p;
    cin >> N >> p;
    long int nums[100010];  // 最后一个测试点，改成long int后通过
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);
    int mycount = -1;
    for (int i = 0; i < N; i++) {
        // 双层循环倒数第二个测试点超时，改成二分法就对了
        // for (int j = N - 1; j >= i && j > mycount + i - 1;
        //      j--) {  // 这里变成等于就对了
        //     if (nums[j] <= nums[i] * p) {
        //         int cnt = j - i + 1;
        //         mycount = max(cnt, mycount);
        //         break;
        //     }
        // }
        int l = i + 1;
        int r = N - 1;
        int m;
        int curcount;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] > nums[i] * p)
                r = m - 1;
            else if (nums[m] < nums[i] * p)
                l = m + 1;
            else
                break;
        }
        if (nums[m] == nums[i] * p) {
            curcount = m - i + 1;
        } else
            curcount = l - i;
        // 二分法结束之后，如果不是正好找到，那就是r是比它小的，l是比它大的
        // 这里其实应该是l-1-i+1，最后就是l-i
        mycount = max(mycount, curcount);
    }
    mycount = max(mycount, 0);
    cout << mycount;
}