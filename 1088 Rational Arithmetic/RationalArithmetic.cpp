#include <stdio.h>

#include <iostream>
using namespace std;
typedef struct Frac {
    long long a;
    long long b;
} frac;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
frac simply(frac num) {
    if (num.a < 0 && num.b < 0) {
        num.a = -num.a;
        num.b = -num.b;
    }
    if (num.a > 0 && num.b < 0) {
        num.a = -num.a;
        num.b = -num.b;
    }
    long long fac = gcd(num.a, num.b);
    fac = fac > 0 ? fac : -fac;
    while (fac != 1) {
        num.a /= fac;
        num.b /= fac;
        fac = fac = gcd(num.a, num.b);
        fac = fac > 0 ? fac : -fac;
    }
    return num;
}
frac input() {
    long long a, b;
    scanf("%lld/%lld", &a, &b);
    frac num;
    num.a = a;
    num.b = b;
    return num;
}
void output(frac num) {
    if (num.a == 0) {
        cout << "0";
        return;
    }
    if (num.a < 0) {
        cout << "(";
        long long zhengshu = num.a / num.b;
        long long remain = num.a - num.b * zhengshu;
        if (zhengshu != 0) cout << zhengshu;
        if (zhengshu != 0 && remain != 0) cout << " ";
        if (zhengshu != 0) remain = -remain;
        if (remain != 0) cout << remain << "/" << num.b;
        cout << ")";
        return;
    }
    if (num.a > 0) {
        long long zhengshu = num.a / num.b;
        long long remain = num.a - num.b * zhengshu;
        if (zhengshu != 0) cout << zhengshu;
        if (zhengshu != 0 && remain != 0) cout << " ";
        if (remain != 0) cout << remain << "/" << num.b;
        return;
    }
}
int main() {
    frac a, b, res;
    a = input();
    a = simply(a);
    b = input();
    b = simply(b);

    // 加法
    res.a = a.a * b.b + a.b * b.a;
    res.b = a.b * b.b;
    res = simply(res);
    output(a);
    cout << " + ";
    output(b);
    cout << " = ";
    output(res);
    cout << endl;

    // 减法
    res.a = a.a * b.b - a.b * b.a;
    res.b = a.b * b.b;
    res = simply(res);
    output(a);
    cout << " - ";
    output(b);
    cout << " = ";
    output(res);
    cout << endl;

    // 乘法
    res.a = a.a * b.a;
    res.b = a.b * b.b;
    res = simply(res);
    output(a);
    cout << " * ";
    output(b);
    cout << " = ";
    output(res);
    cout << endl;

    // 除法
    if (b.a == 0) {
        output(a);
        cout << " * ";
        output(b);
        cout << " = Inf";
        return 0;
    }
    res.a = a.a * b.b;
    res.b = a.b * b.a;
    res = simply(res);
    output(a);
    cout << " / ";
    output(b);
    cout << " = ";
    output(res);
    cout << endl;
    return 0;
}
