#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int cou[100000];
bool e[100000];
int main() {
    fill(e, e + 100000, false);
    fill(cou, cou + 100000, -1);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cou[x] = y;
        cou[y] = x;
    }
    int M;
    cin >> M;
    vector<int> list;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        list.push_back(x);
        e[x] = true;
    }
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < M; i++) {
        int x = list[i];
        int y = cou[x];
        if (y == -1) {
            res.push_back(x);
        }
        if (y != -1 && e[y] == false) {
            res.push_back(x);
        }
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) cout << " ";
        // cout<<res[i];
        printf("%05d", res[i]);
    }
    return 0;
}