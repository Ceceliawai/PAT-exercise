#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int num[100010], sorted[100010], N;
bool existed[100010];  // 是否出现过
vector<int> res;       // 存放结果
map<int, int> numtoi;  // 数对应的在num里面的index
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        sorted[i] = num[i];
        numtoi[num[i]] = i;
    }
    int leftmax, rightmin;
    sort(sorted, sorted + N);
    fill(existed, existed + N, false);
    leftmax = -1;
    rightmin = sorted[0];
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        // 如果满足左面都小右面都大，则可以是一个划分
        if (leftmax <= num[i] && rightmin >= num[i]) {
            res.push_back(num[i]);
        }
        existed[i] = true;
        // 左面已经出现的最大的
        leftmax = max(leftmax, num[i]);
        // 找到未出现的最小的那个，就是右面的最小的
        for (int j = cnt; j < N; j++) {
            int index = numtoi[sorted[j]];
            if (existed[index] == false) {
                rightmin = sorted[j];
                cnt = j;
                break;
            }
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}