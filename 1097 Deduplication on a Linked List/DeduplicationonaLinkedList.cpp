#include <stdio.h>

#include <algorithm>
#include <iostream>
using namespace std;
int point[100010];
int key[100010];
bool exist[10010];
int root, N, add, pnext, val;
int fabs(int num) { return num > 0 ? num : -num; }
int main() {
    cin >> root >> N;
    for (int i = 0; i < N; i++) {
        cin >> add >> val >> pnext;
        point[add] = pnext;
        key[add] = val;
    }
    int p = root;
    int pre = -1;
    pnext = -1;
    fill(exist, exist + 10010, false);
    int newroot = -1;
    int newpre = -1;
    while (p != -1) {
        pnext = point[p];
        if (exist[fabs(key[p])] == true) {
            point[pre] = pnext;
            point[p] = -1;
            if (newroot == -1) {
                newroot = p;
                newpre = p;
            } else {
                point[newpre] = p;
                newpre = p;
            }
            // pre不变
        } else {
            pre = p;
        }
        exist[fabs(key[p])] = true;
        p = pnext;
    }

    p = root;
    while (p != -1) {
        pnext = point[p];
        if (pnext != -1) {
            printf("%05d %0d %05d\n", p, key[p], pnext);
        } else {
            printf("%05d %0d -1\n", p, key[p]);
        }
        p = pnext;
    }
    p = newroot;
    while (p != -1) {
        pnext = point[p];
        if (pnext != -1) {
            printf("%05d %0d %05d\n", p, key[p], pnext);
        } else {
            printf("%05d %0d -1\n", p, key[p]);
        }
        p = pnext;
    }
    return 0;
}