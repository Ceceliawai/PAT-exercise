#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int point[100000];  // the address next
char val[100000];   // the data the address store

int N;       // total number of nodes
int s1, s2;  // start address of string

int main() {
    fill(point, point + 10000, -1);  // initial
    cin >> s1 >> s2 >> N;
    for (int i = 0; i < N; i++) {
        int a, n;
        char d;
        cin >> a >> d >> n;
        point[a] = n;
        val[a] = d;
    }

    int l1 = 0;
    int p = s1;
    while (point[p] != -1) {
        l1++;
        p = point[p];
    }

    int l2 = 0;
    p = s2;
    while (point[p] != -1) {
        l2++;
        p = point[p];
    }

    int p1 = s1;
    int p2 = s2;
    if (l1 > l2) {
        for (int i = 0; i < l1 - l2; i++) {
            p1 = point[p1];
        }
    } else if (l2 > l1) {
        for (int i = 0; i < l2 - l1; i++) {
            p2 = point[p2];
        }
    }

    while (p1 != -1 && p2 != -1) {
        if (p1 == p2) {
            break;
        }
        p1 = point[p1];
        p2 = point[p2];
    }
    if (p1 != -1 && p2 != -1)
        printf("%05d", p1);
    else
        cout << "-1";
}