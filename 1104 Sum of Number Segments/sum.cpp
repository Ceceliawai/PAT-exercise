#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long double num[100010];
int main() {
    vector<long double> t;
    long double res = 0;  // 第三个测试点是精度
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%Lf", &num[i]);
    }
    int a = N;
    int b = 1;
    for (int i = 0; i < N; i++) {
        res += num[i] * a * b;
        a--;
        b++;
    }
    printf("%.2Lf", res);
}