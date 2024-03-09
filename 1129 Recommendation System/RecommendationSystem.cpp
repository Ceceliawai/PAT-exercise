#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int d[500010];
bool mycmp(int x, int y) {
    if (d[x] != d[y]) return d[x] > d[y];
    return x < y;
}
int main() {
    fill(d, d + 500010, 0);
    int N, K;
    cin >> N >> K;
    int num;
    cin >> num;
    vector<int> v;
    v.push_back(num);
    d[num]++;
    for (int i = 1; i < N; i++) {
        sort(v.begin(), v.end(), mycmp);
        cin >> num;
        cout << num << ":";
        for (int j = 0; j < K && j < v.size(); j++) {
            cout << " ";
            cout << v[j];
        }
        cout << endl;
        d[num]++;
        if (v.size() < 10) {
            if (count(v.begin(), v.end(), num) == 0) {
                v.push_back(num);
            }
        } else {
            // K最大是10，因此v里面最多保存10个就行了
            if (d[num] > d[v[v.size() - 1]]) {
                v.pop_back();
                v.push_back(num);
            } else if (d[num] == d[v[v.size() - 1]]) {
                if (num < v[v.size() - 1]) {
                    v.pop_back();
                    v.push_back(num);
                }
            }
        }
    }
    return 0;
}