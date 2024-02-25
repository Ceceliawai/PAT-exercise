#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a, b, num, pre;
int digits[4];
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }
void getdigits(int num) {
    int cnt = 0;
    while (num != 0) {
        digits[cnt] = num % 10;
        num /= 10;
        cnt++;
    }
    while (cnt != 4) {
        digits[cnt] = 0;
        cnt++;
    }
    return;
}
int getnum() {
    int num = digits[0];
    num = num * 10 + digits[1];
    num = num * 10 + digits[2];
    num = num * 10 + digits[3];
    return num;
}
int main() {
    cin >> num;
    getdigits(num);
    sort(digits, digits + 4, cmp2);
    a = getnum();
    sort(digits, digits + 4, cmp1);
    b = getnum();
    num = a - b;
    pre = num;
    printf("%04d - %04d = %04d\n", a, b, num);
    while (true) {
        getdigits(num);
        sort(digits, digits + 4, cmp2);
        a = getnum();
        sort(digits, digits + 4, cmp1);
        b = getnum();
        if (a - b == pre)
            break;
        else {
            num = a - b;
            pre = num;
            printf("%04d - %04d = %04d\n", a, b, num);
        }
    }
    return 0;
}
