#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int quota[110];  // 大学招生容量
int GE[40010], GI[40010], choice[40010][5];
vector<int> stu[110];  // 大学的学生的编号
int lowg[110][2];      // 当前大学的最低分 0是总分 1是GE的分数
vector<int> alls;      // 所有学生的ranklist
int N, M, K;
bool mycmp(int a, int b) {
    double at = (GE[a] + GI[a]) / 2;
    double bt = (GE[b] + GI[b]) / 2;
    if (at != bt) return at > bt;
    return GE[a] > GE[b];
}
int main() {
    cin >> N >> M >> K;
    fill(quota, quota + 110, -1);
    fill(lowg[0], lowg[0] + 110 * 2, -1);
    for (int i = 0; i < M; i++) cin >> quota[i];
    for (int i = 0; i < N; i++) {
        alls.push_back(i);
        cin >> GE[i] >> GI[i];
        for (int j = 0; j < K; j++) {
            cin >> choice[i][j];
        }
    }
    sort(alls.begin(), alls.end(), mycmp);
    for (int i = 0; i < N; i++) {
        int curs = alls[i];
        for (int j = 0; j < K; j++) {
            int curc = choice[curs][j];
            if (quota[curc] > 0) {
                // 进入到这个学校了
                stu[curc].push_back(curs);
                lowg[curc][0] = (GE[curs] + GI[curs]) / 2;
                lowg[curc][1] = GE[curs];
                quota[curc]--;
                break;
            } else {
                // 名额不够 判断分数是否一样
                if (lowg[curc][0] == (GE[curs] + GI[curs]) / 2 &&
                    lowg[curc][1] == GE[curs]) {
                    stu[curc].push_back(curs);
                    quota[curc]--;
                }
            }
        }
    }
    for (int i = 0; i < M; i++) {
        // if(i!=0)cout<<endl;
        sort(stu[i].begin(), stu[i].end());
        for (int j = 0; j < stu[i].size(); j++) {
            if (j != 0) cout << " ";
            cout << stu[i][j];
        }
        cout << endl;
    }
    return 0;
}