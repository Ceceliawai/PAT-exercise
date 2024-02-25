#include <stdio.h>

#include <algorithm>
#include <iostream>
using namespace std;
int N, D;
double p[1010], m[1010];
int order[1010];
bool mycmp(int a, int b) {
    double x = p[a] * 1.0 / m[a];
    double y = p[b] * 1.0 / m[b];
    return x > y;
}
int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) cin >> m[i];
    for (int i = 0; i < N; i++) cin >> p[i];
    for (int i = 0; i < N; i++) order[i] = i;
    sort(order, order + N, mycmp);
    double total = 0;
    for (int i = 0; i < N && D >= 0; i++) {
        int index = order[i];
        if (D >= m[index]) {
            total += p[index];
            D -= m[index];
        } else {
            total += p[index] * 1.0 * D / m[index];
            D = 0;
            break;
        }
    }
    printf("%.2f", total);
}