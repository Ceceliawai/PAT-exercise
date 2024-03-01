#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef struct Node {
    int i, j, k;
} node;
int M, N, L, T;
bool visited[60][1286][128];
int w[60][1286][128];
/**
 * @brief 深度优先搜索 但深度优先搜索会导致大数据的时候段错误
 *
 * @param ri 坐标1
 * @param rj 坐标2
 * @param rk 坐标3
 * @return ** int
 */
int dfs(int ri, int rj, int rk) {
    int curval = 0;
    visited[ri][rj][rk] = true;
    if (ri - 1 >= 0 && visited[ri - 1][rj][rk] == false &&
        w[ri - 1][rj][rk] != 0)
        curval += dfs(ri - 1, rj, rk);
    if (ri + 1 < L && visited[ri + 1][rj][rk] == false &&
        w[ri + 1][rj][rk] != 0)
        curval += dfs(ri + 1, rj, rk);
    if (rj - 1 >= 0 && visited[ri][rj - 1][rk] == false &&
        w[ri][rj - 1][rk] != 0)
        curval += dfs(ri, rj - 1, rk);
    if (rj + 1 < M && visited[ri][rj + 1][rk] == false &&
        w[ri][rj + 1][rk] != 0)
        curval += dfs(ri, rj + 1, rk);
    if (rk - 1 >= 0 && visited[ri][rj][rk - 1] == false &&
        w[ri][rj][rk - 1] != 0)
        curval += dfs(ri, rj, rk - 1);
    if (rk + 1 < N && visited[ri][rj][rk + 1] == false &&
        w[ri][rj][rk + 1] != 0)
        curval += dfs(ri, rj, rk + 1);
    curval += w[ri][rj][rk];
    return curval;
}
/**
 * @brief 遍历的bfs版本，AC。注意在入队之后就要标记visited，否则会重复入队
 *
 * @param ri
 * @param rj
 * @param rk
 * @return ** int
 */
int bfs(int ri, int rj, int rk) {
    queue<node> q;
    node temp;
    node newn;
    temp.i = ri;
    temp.j = rj;
    temp.k = rk;
    visited[ri][rj][rk] = true;
    q.push(temp);
    int val = 0;
    while (q.empty() == false) {
        temp = q.front();
        q.pop();
        val += w[temp.i][temp.j][temp.k];
        visited[temp.i][temp.j][temp.k] = true;
        if (temp.i - 1 >= 0 && visited[temp.i - 1][temp.j][temp.k] == false &&
            w[temp.i - 1][temp.j][temp.k] != 0) {
            newn.i = temp.i - 1;
            newn.j = temp.j;
            newn.k = temp.k;
            visited[newn.i][newn.j][newn.k] = true;
            q.push(newn);
        }
        if (temp.i + 1 < L && visited[temp.i + 1][temp.j][temp.k] == false &&
            w[temp.i + 1][temp.j][temp.k] != 0) {
            newn.i = temp.i + 1;
            newn.j = temp.j;
            newn.k = temp.k;
            visited[newn.i][newn.j][newn.k] = true;
            q.push(newn);
        }
        if (temp.j - 1 >= 0 && visited[temp.i][temp.j - 1][temp.k] == false &&
            w[temp.i][temp.j - 1][temp.k] != 0) {
            newn.i = temp.i;
            newn.j = temp.j - 1;
            newn.k = temp.k;
            visited[newn.i][newn.j][newn.k] = true;
            q.push(newn);
        }
        if (temp.j + 1 < M && visited[temp.i][temp.j + 1][temp.k] == false &&
            w[temp.i][temp.j + 1][temp.k] != 0) {
            newn.i = temp.i;
            newn.j = temp.j + 1;
            newn.k = temp.k;
            visited[newn.i][newn.j][newn.k] = true;
            q.push(newn);
        }
        if (temp.k - 1 >= 0 && visited[temp.i][temp.j][temp.k - 1] == false &&
            w[temp.i][temp.j][temp.k - 1] != 0) {
            newn.i = temp.i;
            newn.j = temp.j;
            newn.k = temp.k - 1;
            visited[newn.i][newn.j][newn.k] = true;
            q.push(newn);
        }
        if (temp.k + 1 < N && visited[temp.i][temp.j][temp.k + 1] == false &&
            w[temp.i][temp.j][temp.k + 1] != 0) {
            newn.i = temp.i;
            newn.j = temp.j;
            newn.k = temp.k + 1;
            visited[newn.i][newn.j][newn.k] = true;
            q.push(newn);
        }
    }
    return val;
}
int main() {
    fill(visited[0][0], visited[0][0] + 60 * 1286 * 128, false);
    fill(w[0][0], w[0][0] + 60 * 1286 * 128, 0);
    cin >> M >> N >> L >> T;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                cin >> w[i][j][k];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (visited[i][j][k] == false && w[i][j][k] != 0) {
                    // int cur = dfs(i, j, k);
                    int cur = bfs(i, j, k);
                    if (cur >= T) res += cur;
                }
            }
        }
    }
    cout << res;
    return 0;
}
