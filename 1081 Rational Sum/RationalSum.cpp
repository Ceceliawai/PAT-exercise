#include <stdio.h>

#include <iostream>
using namespace std;
typedef struct myFrac {
    int n;
    int d;
} frac;
frac inputF() {
    frac f;
    scanf("%d/%d", &f.n, &f.d);
    return f;
}
frac simplize(frac a) {
    bool flag = true;
    while (flag == true) {
        flag = false;
        for (int i = 2; i <= a.n && i <= a.d; i++) {
            if (a.n % i == 0 && a.d % i == 0) {
                a.n /= i;
                a.d /= i;
                flag = true;
                break;
            }
        }
    }
    return a;
}
int main() {
    frac a, b;
    int N;
    cin >> N;
    a = inputF();
    for (int i = 1; i < N; i++) {
        b = inputF();
        a.n = a.n * b.d + b.n * a.d;
        a.d = a.d * b.d;
        a = simplize(a);
    }
    int zhengshu = a.n / a.d;
    a.n = a.n - zhengshu * a.d;
    if (zhengshu != 0) cout << zhengshu;
    if (zhengshu != 0 && a.n != 0) cout << " ";
    if (a.n != 0) cout << a.n << "/" << a.d;
    return 0;
}
