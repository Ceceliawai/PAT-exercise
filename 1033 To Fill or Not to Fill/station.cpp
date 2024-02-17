#include <stdio.h>

#include <algorithm>
#include <iostream>

using namespace std;

#define INF 9999999

double ndis = 0;    // 当前坐标
double nprice = 0;  // 当前价格
double ngas = 0;    // 当前所剩汽油数，初始为0
int Cmax, D, Davg, N;
int oncemax;  // 油箱加满走出的最远距离
int cnt = 0;  // 当前到的加油站
int dis;

typedef struct Station {
    int distance;
    double price;
} station;

station s[500];  // 加油站结构体

bool cmp(station s1, station s2) { return s1.distance < s2.distance; }

int main() {
    cin >> Cmax >> D >> Davg >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i].price;
        cin >> s[i].distance;
    }
    sort(s, s + N, cmp);  // 按距离从近到远排序

    bool flag = true;
    oncemax = Cmax * Davg;

    while (true) {
        if (cnt == 0) {
            dis = s[cnt].distance;
            if (dis != 0) {
                flag = false;
                break;
            }
        } else if (cnt < N - 1)
            dis = s[cnt + 1].distance - s[cnt].distance;
        else
            dis = D - s[cnt].distance;  // 没有剩余的加油站了，距离目的地的距离
        if (dis > oncemax) {
            ndis = ndis + oncemax;  // 更新能跑的最远的距离，即加满油跑最后一次
            flag = false;  // 到不了目的地
            break;
        }

        if (ndis + dis == D) {
            // 到目的地了，加刚好到目的地的就行了
            ndis += dis;
            nprice += (dis * 1.0 / Davg) * s[cnt].price;
            break;
        }

        // 找到距离内是否有价格更小的加油站
        double min = s[cnt].price;
        int index = -1;
        for (int i = cnt + 1; i < N; i++) {
            dis = s[i].distance - s[cnt].distance;
            if (dis > oncemax) {
                break;  // 更远的到不了了
            }
            if (s[i].price < min) {
                index = i;
                min = s[i].price;
                break;  // 只要有更小的就到那才加油
            }
        }

        if (index == -1) {
            // 距离内没有更小的，油箱加满
            nprice = nprice + s[cnt].price * (Cmax - ngas);  // 加满的价格
            ngas = Cmax;
            ngas = Cmax - (s[cnt + 1].distance - s[cnt].distance) * 1.0 / Davg;
            cnt++;                   // 去到下一个加油站
            ndis = s[cnt].distance;  // 当前坐标更新；
        }

        else {
            double need = (s[index].distance - s[cnt].distance) * 1.0 /
                          Davg;  // 需要的汽油数
            if (need <= ngas) {
                // 不需要加油 只更新gas数目
                ngas = ngas - need;
            } else {
                nprice =
                    nprice + s[cnt].price *
                                 (need - ngas);  // 加油到刚好到那个更好的加油站
                ngas = 0;
            }
            cnt = index;             // 去到下一个加油站
            ndis = s[cnt].distance;  // 当前坐标更新
        }
    }

    if (flag == false) {
        printf("The maximum travel distance = %.2f", ndis);
        return 0;
    } else {
        printf("%.2f", nprice);
        return 0;
    }
}
