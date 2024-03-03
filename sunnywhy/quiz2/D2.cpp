#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef struct Node {
    int x;
    int y;
} node;
int n, m;
char map[310][310];
long long int mcount[310][310];
vector<node> nodes;
long long int INF = pow(10, 9) + 7;
long long int findc(int x, int y, int rx, int ry) {
    fill(mcount[0], mcount[0] + 310 * 310, 0);
    mcount[x][y] = 1;
    for (int i = x; i <= rx; i++) {
        for (int j = y; j <= ry; j++) {
            if (i - 1 >= x && map[i - 1][j] != '*')
                mcount[i][j] += mcount[i - 1][j];
            mcount[i][j] = mcount[i][j] % INF;
            if (j - 1 >= y && map[i - 1][j] != '*')
                mcount[i][j] += mcount[i][j - 1];
            mcount[i][j] = mcount[i][j] % INF;
            if (map[i][j] == '*') mcount[i][j] = 0;
        }
    }
    return mcount[rx][ry] % INF;
    ;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '#') {
                node newn;
                newn.x = i;
                newn.y = j;
                nodes.push_back(newn);
            }
        }
    }
    long long int a = findc(1, 1, nodes[0].x, nodes[0].y);
    long long int b = findc(nodes[0].x, nodes[0].y, nodes[1].x, nodes[1].y);
    long long int c = findc(nodes[1].x, nodes[1].y, n, m);
    cout << (a * b * c) % INF;
    return 0;
}