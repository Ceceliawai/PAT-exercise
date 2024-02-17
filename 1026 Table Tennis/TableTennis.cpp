#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int H, M, S;       // hour:minute:second
int p, v;          // time to play;vip or not
int C[100000];     // index: the time that customer arrives;
                   // value: the time that customer need to play
int cvip[100000];  // index:time;value:the customer is vip or not
int ResI[10001];   // index:output rank;value:the time customer arrive
int ResO[10001];   // index:output rank;value:the time being served
int ts[101];       // time that table be avialable
int tv[101];       // index:table num;value:is vip or not
int tcount[101];   // the num of pairs of customer table serve
int cnt = 0;       // the total number of pairs of customer served
int Time;          // nowtime
int N, K, m;

vector<int> nor_t;  // all available table
vector<int> vip_t;  // available vip table
vector<int> wait;   // all cus wait queue
vector<int> vwait;  // vip cus wait queue

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d %d", &H, &M, &S, &p, &v);
        int index = H * 3600 + M * 60 + S;
        p = min(p, 120) * 60;  // play time long to 2hour
        cvip[index] = v;
        C[index] = p;
    }
    cin >> K >> m;
    for (int i = 0; i < m; i++) {
        int index;
        cin >> index;
        tv[index] = 1;
    }

    // 按秒钟进行处理
    for (Time = 8 * 60 * 60; Time < 21 * 60 * 60; Time++) {
        // 有新的客人到了吗？
        if (C[Time] != 0 && cvip[Time] == 1) {
            wait.push_back(Time);
            vwait.push_back(Time);
        } else if (C[Time] != 0) {
            wait.push_back(Time);
        }

        // 有可用的桌子吗？
        nor_t.clear();
        vip_t.clear();
        for (int j = 1; j <= K; j++) {
            if (ts[j] <= Time && tv[j] == 1) {
                nor_t.push_back(j);
                vip_t.push_back(j);
            } else if (ts[j] <= Time && tv[j] == 0)
                nor_t.push_back(j);
        }

        while (wait.size() != 0 && nor_t.size() != 0) {
            // 有客人有桌子，一定能分配
            if (vwait.size() != 0 && vip_t.size() != 0) {
                // 优先分配vip客人
                auto cusit = vwait.front();
                vwait.erase(vwait.begin());
                auto tit = vip_t.front();
                vip_t.erase(vip_t.begin());
                ResI[cnt] = cusit;
                ResO[cnt] = Time;
                cnt++;
                tcount[tit]++;
                ts[tit] = Time + C[cusit];  // 更新空闲时间
                auto it = std::find(wait.begin(), wait.end(), cusit);
                wait.erase(it);
                it = std::find(nor_t.begin(), nor_t.end(), tit);
                nor_t.erase(it);
            } else {
                // 按照时间先后分配
                auto cusit = wait.front();
                wait.erase(wait.begin());
                if (cvip[cusit] == 1) {
                    auto it = find(vwait.begin(), vwait.end(), cusit);
                    vwait.erase(it);
                }
                auto tit = nor_t.front();
                nor_t.erase(nor_t.begin());
                if (tv[tit] == 1) {
                    auto it = find(vip_t.begin(), vip_t.end(), tit);
                    vip_t.erase(it);
                }
                ResI[cnt] = cusit;
                ResO[cnt] = Time;
                cnt++;
                tcount[tit]++;
                ts[tit] = Time + C[cusit];  // 更新空闲时间
            }
        }

        // 分配完成，时间自增
    }

    for (int i = 0; i < cnt; i++) {
        H = ResI[i] / 3600;
        M = (ResI[i] % 3600) / 60;
        S = ResI[i] % 60;
        printf("%02d:%02d:%02d ", H, M, S);
        H = ResO[i] / 3600;
        M = (ResO[i] % 3600) / 60;
        S = ResO[i] % 60;
        printf("%02d:%02d:%02d ", H, M, S);
        printf("%d\n", ((ResO[i] - ResI[i]) + 30) /
                           60);  // 记得这里加30，超过半分钟按一分钟算
    }

    for (int i = 1; i <= K; i++) {
        if (i != 1) cout << " ";
        cout << tcount[i];
    }

    return 0;
}