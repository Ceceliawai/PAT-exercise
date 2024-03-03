#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char map[310][310];
long long int mcount[310][310];     // 记录到过的次数
long long int mygive[310][310][2];  // 0 for right(j+1) 1 for down(i+1)
bool visited[310][310];
int n, m;
vector<int> ml;
vector<int> mr;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '#') {
                ml.push_back(i);
                mr.push_back(j);
            }
        }
    }
    int curi = 1;
    int curj = 1;
    fill(mcount[0], mcount[0] + 310 * 310, 0);
    fill(mygive[0][0], mygive[0][0] + 310 * 310 * 2, 0);
    fill(visited[0], visited[0] + 310 * 310, false);
    mcount[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - 1 >= 1) mcount[i][j] += mygive[i - 1][j][1];
            if (j - 1 >= 1) mcount[i][j] += mygive[i][j - 1][0];
            if (i + 1 <= n && map[i + 1][j] == '#')
                mygive[i][j][1] = mcount[i][j];
            else if (j + 1 <= m && map[i][j + 1] == '#')
                mygive[i][j][0] = mcount[i][j];
            else {
                if (i + 1 <= n && map[i + 1][j] != '*')
                    mygive[i][j][1] = mcount[i][j];
                if (j + 1 <= m && map[i + 1][j] != '*')
                    mygive[i][j][0] = mcount[i][j];
            }
        }
    }

    long long int f1 = mcount[ml[0]][mr[0]];
    long long int f2 = mcount[ml[1]][mr[1]];
    if (f1 > 0 && f2 > 0)
        cout << mcount[n][m] % 1000000007;
    else
        cout << "0";
    return 0;
}
