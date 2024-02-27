#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long int bones[20];
int n;
long long int total = 0;
long long int minsub = (0x1) << 30;
vector<int> temp;
long long int cursum = 0;
long long int fabs(long long int a, long long int b) {
    if (a - b > 0) return a - b;
    return b - a;
}
void bfs(int root) {
    cursum += bones[root];
    temp.push_back(root);
    long int cfabs = fabs(cursum, total - cursum);
    minsub = cfabs < minsub ? cfabs : minsub;
    for (int i = root + 1; i < n; i++) {
        bfs(i);
    }
    cursum -= bones[root];
    temp.pop_back();
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bones[i];
        total += bones[i];
    }
    if (n == 2) {
        cout << fabs(bones[0], bones[1]);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        bfs(i);
    }
    cout << minsub;
    return 0;
}