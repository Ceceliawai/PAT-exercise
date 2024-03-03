#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
long int N;
vector<int> temp;
vector<int> t;
vector<int> res;
int maxl = 0;
int main() {
    cin >> N;
    for (int i = 2; i <= sqrt(N); i++) {  // 没有这个sqrt会超时
        // 你想，在sqrtN往上不可能再有连续的因子了，因为肯定会比N更大
        int f = i - 1;  // 从2开始找
        int num = N;
        temp.clear();
        // 找到所有的因子
        while (num != 1 && f <= num) {
            f++;
            if (num % f == 0) {
                temp.push_back(f);
                num = num / f;
            } else
                break;
        }
        if (temp.size() > maxl) {
            res = temp;
            maxl = temp.size();
        }
    }
    if (maxl == 0 && N != 1) {
        cout << "1" << endl;
        cout << N;
        return 0;
    }
    cout << maxl << endl;
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) cout << "*";
        cout << res[i];
    }
    return 0;
}