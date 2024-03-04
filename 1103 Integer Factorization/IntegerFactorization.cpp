#include <math.h>
// 2 和 5 过不了
#include <iostream>
#include <vector>
using namespace std;
int N, K, P;
vector<int> temp;
vector<int> res;
bool findf(int num, int k, int p) {
    if (num == 0 && k == 0) {
        res = temp;
        return true;
    }
    if (num < 0 || k == 0) return false;
    int i = pow(num / k, 1.0 / p) + 1;
    for (; i >= 1; i--) {
        temp.push_back(i);
        if (findf(num - pow(i, p), k - 1, p) == true) return true;
        temp.pop_back();
    }
    return false;
}
int main() {
    cin >> N >> K >> P;
    bool f = findf(N, K, P);
    if (res.size() == 0)
        cout << "Impossible";
    else {
        cout << N;
        cout << " =";
        for (int i = 0; i < res.size(); i++) {
            if (i != 0) cout << " +";
            cout << " ";
            cout << res[i];
            cout << "^";
            cout << P;
        }
    }
    return 0;
}