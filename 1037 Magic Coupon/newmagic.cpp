#include <algorithm>
#include <iostream>

using namespace std;

int c[100000];
int p[100000];
int Nc, Np;

bool cmp(int a, int b) { return a > b; }

// 负数不买就好了，不用非得买
int main() {
    cin >> Nc;
    for (int i = 0; i < Nc; i++) {
        cin >> c[i];
    }
    cin >> Np;
    for (int i = 0; i < Np; i++) {
        cin >> p[i];
    }
    sort(c, c + Nc);
    sort(p, p + Np);
    int val = 0;
    for (int i = 0; i < Nc && i < Np; i++) {
        if (c[i] < 0 && p[i] < 0)
            val += c[i] * p[i];
        else
            break;
    }
    int i, j;
    for (i = Nc - 1, j = Np - 1; i >= 0 && j >= 0; i--, j--) {
        if (c[i] > 0 && p[j] > 0)
            val += c[i] * p[j];
        else
            break;
    }
    cout << val;
    return 0;
}