#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
long int Primes[10000000];
bool isPrim(long int num) {
    for (long int i = 2; i < num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main() {
    long int N;
    cin >> N;
    if (N == 1) {
        cout << "1=1" << endl;
        return 0;
    }
    vector<int> res;
    long int temp = N;
    int pcount = 0;
    for (int i = 2; i < sqrt(N) + 1; i++) {
        if (isPrim(i) == true) {
            Primes[pcount] = i;
            pcount++;
        }
    }
    bool flag = false;
    int lastid = 0;
    while (temp != 1) {
        flag = false;
        for (int i = lastid; i < pcount; i++) {
            if (temp % Primes[i] == 0) {
                res.push_back(Primes[i]);
                temp = temp / Primes[i];
                flag = true;
                lastid = max(lastid, i);
                break;
            }
        }
        if (flag == false) break;
    }
    if (flag == false && temp == N) {
        cout << N << "=" << N;
        return 0;
    }
    int curnum = res[0];
    int curcount = 1;
    cout << N << "=";
    for (int i = 1; i < res.size(); i++) {
        if (res[i] != curnum) {
            if (curnum != res[0]) cout << "*";
            cout << curnum;
            if (curcount != 1) cout << "^" << curcount;
            curcount = 1;
            curnum = res[i];
        } else
            curcount++;
    }
    if (curnum != res[0]) cout << "*";
    cout << curnum;
    if (curcount != 1) cout << "^" << curcount;
    cout << endl;
    return 0;
}
