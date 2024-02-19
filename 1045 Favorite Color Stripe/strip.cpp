#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> colortorank;
vector<int> colorrank;
vector<int> strip;
int d[10010];

int main() {
    int N, M, K;
    cin >> N;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        int k;
        cin >> k;
        colorrank.push_back(k);
        colortorank.insert(make_pair(k, i));
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;
        if (count(colorrank.begin(), colorrank.end(), k) != 0) {
            int rank = colortorank[k];
            strip.push_back(rank);
        }
    }

    int length = strip.size();
    int res = -1;
    for (int i = 0; i < length; i++) {
        d[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (strip[j] <= strip[i] && d[j] + 1 > d[i]) d[i] = d[j] + 1;
        }
        res = max(res, d[i]);
    }
    cout << res;
    return 0;
}