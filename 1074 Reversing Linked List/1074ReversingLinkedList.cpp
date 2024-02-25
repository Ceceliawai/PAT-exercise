#include <stdio.h>

#include <iostream>
#include <map>
using namespace std;
int point[1000000];
int mydata[1000000];
int root, N, K, newroot;
map<int, int> indextoadd;  // 这个index是不变的，变的是指针的内容
int main() {
    cin >> root >> N >> K;
    newroot = root;
    for (int i = 0; i < N; i++) {
        int add, cdata, next;
        cin >> add >> cdata >> next;
        point[add] = next;
        mydata[add] = cdata;
    }
    int p = root;
    int cnt = 0;
    while (p != -1) {
        indextoadd[cnt] = p;
        p = point[p];
        cnt++;
    }
    int pre = -1;
    int i;
    for (i = 0; i < cnt; i = i + K) {
        if (i + K > cnt) break;
        for (int j = i + K - 1; j >= i; j--) {
            int curad = indextoadd[j];
            if (pre != -1)
                point[pre] = indextoadd[j];
            else
                newroot = indextoadd[j];
            pre = indextoadd[j];
        }
    }
    if (i == cnt)  // 后面没有别的了，恰好完成
        point[pre] = -1;
    else
        point[pre] = indextoadd[i];
    p = newroot;
    while (p != -1) {
        printf("%05d %d ", p, mydata[p]);
        p = point[p];
        if (p != -1)
            printf("%05d\n", p);
        else
            cout << "-1" << endl;
    }
    return 0;
}