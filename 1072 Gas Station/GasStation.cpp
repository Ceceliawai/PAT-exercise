#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int INF = (0x1) << 30;
int N, M, K, Ds, e[1020][1020], d[11][1020];
bool visited[1020];
int choice = -1;  // 选择的gas位置
double md = 0;
double avg;
// 1~N存居民 N+1~N+M存gas station
int main() {
    cin >> N >> M >> K >> Ds;
    fill(e[0], e[0] + 1020 * 1020, INF);
    fill(d[0], d[0] + 11 * 1020, INF);
    // 处理输入
    for (int i = 0; i < K; i++) {
        string a, b;
        int ai, bi, k;
        cin >> a >> b >> k;
        if (a[0] != 'G') {
            ai = stoi(a);
        } else {
            a = a.substr(1);
            ai = stoi(a) + N;
        }
        if (b[0] != 'G') {
            bi = stoi(b);
        } else {
            b = b.substr(1);
            bi = stoi(b) + N;
        }
        e[ai][bi] = k;
        e[bi][ai] = k;
    }
    for (int k = 1; k <= M; k++) {  // 遍历所有的候选人
        // dijkstra主体函数

        // 初始化
        d[k][N + k] = 0;  // N+k就是此次dij的源点
        fill(visited + 1, visited + N + M + 1, false);
        for (int i = 1; i <= N + M; i++) {  // dijkstra外循环N+M次
            int u = -1;
            int mind = INF;
            for (int j = 1; j <= N + M; j++) {
                if (visited[j] == false && d[k][j] < mind) {
                    // 找到距离最短的那个点加入
                    mind = d[k][j];
                    u = j;
                }
            }
            if (mind > Ds) break;  // 不能服务所有居民区了，相当于一个剪枝
            if (u == -1) break;  // 所有的最短距离都找到了
            visited[u] = true;   // 访问当前结点
            // 加入当前点之后，更新最短距离
            for (int j = 1; j <= N + M; j++) {
                if (d[k][j] > e[u][j] + d[k][u]) d[k][j] = e[u][j] + d[k][u];
            }
        }
        double total = 0;
        bool flag = true;
        int c = INF;
        for (int j = 1; j <= N; j++) {
            c = min(d[k][j], c);
            if (d[k][j] > Ds) {
                flag = false;
                break;
            } else
                total += d[k][j];
        }
        if (flag == true) {
            total = total * 1.0 / N;
            if (c > md) {
                md = c;
                avg = total;
                choice = k;
            }
            if (c == md && total < avg) {
                md = c;
                avg = total;
                choice = k;
            }
        }
    }

    if (choice == -1)
        cout << "No Solution";
    else {
        cout << "G" << choice << endl;
        printf("%.1f %.1f", md, avg);
    }
    return 0;
}