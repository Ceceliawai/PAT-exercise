/*
 需要注意的几个点：
 1. 编译不通过，分数是-1，但list输出的时候输出0，需要和完全没提交区分开
 2. 多次提交取最高
 */
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;                // number of users;
int K;                // number of problems
int M;                // number of submisions：注意多次提交取最高
int score[10010][6];  // 0存总数 后面的存对应的题目
int fullscore[6];
int pcount[10010];  // 存pass的题目的个数
vector<int> list;   // 所有要输出的id的vector
bool mycmp(int a, int b) {
    if (score[a][0] != score[b][0]) return score[a][0] >= score[b][0];
    if (pcount[a] != pcount[b])
        return pcount[a] > pcount[b];
    else
        return a < b;
}
int main() {
    cin >> N >> K >> M;
    fill(score[0], score[0] + 10010 * 6, -2);  // 初始化
    fill(pcount, pcount + 10010, 0);
    for (int i = 1; i <= K; i++) cin >> fullscore[i];
    for (int i = 0; i < M; i++) {
        int id, pnum, s;
        cin >> id >> pnum >> s;
        score[id][pnum] = max(score[id][pnum], s);
    }
    for (int i = 1; i <= N; i++) {
        int total = 0;
        bool flag = false;
        for (int j = 1; j <= K; j++) {
            if (score[i][j] >= 0) {
                total += score[i][j];
                flag = true;
            }
            if (score[i][j] == fullscore[j]) {
                pcount[i]++;
            }
        }
        score[i][0] = total;
        if (flag == true) list.push_back(i);
    }
    sort(list.begin(), list.end(), mycmp);
    int pre = -1;
    int cnt = 0;
    int prerank;
    for (int i = 0; i < list.size(); i++) {
        int id = list[i];
        // rank
        if (score[id][0] != pre) {
            cout << cnt + 1;
            prerank = cnt + 1;
            pre = score[id][0];
        } else {
            cout << prerank;
        }
        cnt++;
        cout << " ";
        // id
        printf("%05d ", id);
        for (int j = 0; j <= K; j++) {
            if (j != 0) cout << " ";
            if (score[id][j] >= 0)
                cout << score[id][j];
            else if (score[id][j] == -1)
                cout << "0";
            else
                cout << "-";
        }
        cout << endl;
    }
    return 0;
}
