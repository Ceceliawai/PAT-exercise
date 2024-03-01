#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
char v[100010];
long long int cnt = 0;
long long int mcount[100010][3];  // �����indexΪֹ�ж��ٸ�P A T
long long int Pnt, Ant, Tnt;
// ������⣬��ʱ
int bfs(int root) {
    if (v[root] == 'P') {
        int n = 0;
        for (int i = root + 1; i < cnt; i++) {
            if (v[i] == 'A') n += bfs(i);
        }
        return n;
    }
    if (v[root] == 'A') {
        int n = 0;
        for (int i = root + 1; i < cnt; i++) {
            if (v[i] == 'T') n++;
        }
        return n;
    }
    return 0;
}
int main() {
    fill(mcount[0], mcount[0] + 100010, 0);
    char op = getchar();
    Pnt = Ant = Tnt = 0;
    while (op != '\n') {
        v[cnt] = op;
        if (op == 'A') Ant++;
        if (op == 'P') Pnt++;
        if (op == 'T') Tnt++;
        mcount[cnt][0] = Pnt;
        mcount[cnt][1] = Ant;
        mcount[cnt][2] = Tnt;
        op = getchar();
        cnt++;
    }
    long long int n = 0;
    // ���������Ե㳬ʱ
    // for(int i=0;i<cnt;i++){
    //     if(v[i]=='P')n+=bfs(i);
    // }
    for (long long int i = 0; i < cnt; i++) {
        long long int a, b, c;
        if (v[i] == 'A') {
            // ����������ҵ����ٸ�T
            a = mcount[i][0];  // ����ǰ�����֮ǰ�ж��ٸ�P
            b = mcount[cnt - 1][2] - mcount[i][2];  // �����֮���T
            n += a * b;
        }
    }
    cout << n % 1000000007;
}
