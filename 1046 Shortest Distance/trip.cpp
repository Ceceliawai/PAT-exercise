#include <iostream>
#include <vector>
using namespace std;
int d[100001];
int N, M, L = 0;
int main() {
    cin >> N;
    int ral = 0;
    d[1] = 0;
    for (int i = 2; i <= N; i++) {
        cin >> ral;
        L += ral;
        d[i] = L;
    }
    cin >> ral;
    L += ral;

    cin >> M;
    vector<int> res;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        int a = max(s, e);
        int b = min(s, e);
        int c = d[a] - d[b];
        c = min(L - c, c);
        res.push_back(c);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}