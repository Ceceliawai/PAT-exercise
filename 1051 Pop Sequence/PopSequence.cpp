#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int indata[1010];
bool output[1010];
vector<int> res;
int main() {
    int N, M, K, maxl, len, maxo = -1;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        // 处理一行的输入
        fill(output + 1, output + N + 1, false);
        maxl = -1;
        len = 1;
        cin >> indata[0];
        maxo = -1;
        maxo = max(maxo, indata[0]);
        output[indata[0]] = true;
        bool flag = true;
        for (int j = 1; j < N; j++) {
            cin >> indata[j];
            if (flag == false) continue;
            for (int k = maxo - 1; k > indata[j]; k--) {
                if (output[k] == false) {
                    flag = false;
                    break;
                }
            }
            maxo = max(maxo, indata[j]);
            output[indata[j]] = true;
            if (indata[j] > indata[j - 1])
                len = 1;
            else
                len++;
            maxl = max(maxl, len);
        }
        if (flag == false) {
            res.push_back(0);
            continue;
        }
        if (maxl > M) {
            res.push_back(0);
            continue;
        }
        res.push_back(1);
    }

    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}