#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
struct table {
    int endtime, num;
    bool vip;
};
struct play {
    int arrive, use, start;  // 到达时间，使用时间，开始时间
    bool served, vip;        // 是否服务，vip?
};
int cmp1(play a, play b) {
    return a.arrive < b.arrive;  // 先对数据进行排序，按到达的时间升序
}
int cmp2(play a, play b) {
    return a.start <
           b.start;  // 最后输出的时候为什么是8:12:00在8:10:00的前面呢？就是因为是按
}  // 开始使用的时间升序的
vector<play> p;
vector<table> t;

// 找到personid及之后的，并且到达（arrive）时间不晚于before的，未服务的，且为vip的
// person-id如果没找到，则返回 - 1 ，findvip(personId, minEndTime);

int findvip(int personId, int minendtime) {
    for (int i = personId; i < p.size() && p[i].arrive <= minendtime; i++) {
        if (!p[i].served && p[i].vip) return i;
    }
    return -1;
}
// 更新以personId的玩家对，和tableId的桌子的信息
//    包括：
//      1、将该玩家对的开始时间赋值为到达时间和可用桌子结束时间中的较大值
//    2、将该玩家对的服务状态赋值为以服务过
//  3、将桌子的结束时间信息更新为该玩家对的开始时间加该玩家的使用时间
// 4、将该桌子服务的玩家数量加一

void update(int personid, int tableid) {
    p[personid].start = max(p[personid].arrive, t[tableid].endtime);
    p[personid].served = 1;
    t[tableid].endtime = p[personid].start + p[personid].use;
    t[tableid].num++;
}

int main() {
    int n, m, k, vipnum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m, s, use, vip, arrive;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &use, &vip);
        arrive = h * 3600 + m * 60 + s;
        use = use > 120 ? 7200 : use * 60;
        p.push_back({arrive, use, 0, 0, vip > 0});
    }
    sort(p.begin(), p.end(), cmp1);
    scanf("%d %d", &k, &m);
    for (int i = 0; i < k; i++) t.push_back({28800, 0, 0});
    for (int i = 0; i < m; i++) {
        scanf("%d", &vipnum);
        t[vipnum - 1].vip = 1;
    }
    for (int i = 0; i < p.size();) {
        // 找到最先空闲的桌子,如果多个桌子同时空闲，则返回桌子号最小的那个
        int minendtime = INT_MAX, minendid;
        for (int j = 0; j < k; j++) {
            if (minendtime > t[j].endtime) {
                minendtime = t[j].endtime;
                minendid = j;
            }
        }
        // 如果最先空闲的桌子空闲的太晚了，或者当前序列中的第一位玩家对达到的时间太晚了，就退出循环
        if (minendtime >= 75600 || p[i].arrive >= 75600) break;
        // 声明新的变量，personId为经过调整选择后最终的开始使用桌子的玩家对索引，tableId为为经过调整选择后最终的开始被使用的桌子
        int personid = i, tableid = minendid;
        // 如果当前的最早空闲且号最小的桌子空闲时，存在玩家对已经在等待了
        if (minendtime >= p[i].arrive) {
            // 并且当前的最早空闲且号最小的桌子是vip，寻找是vip的且未服务过的，玩家对到达时间不晚于minEndTime的玩家对索引
            if (t[tableid].vip) {
                int vipid = findvip(personid, minendtime);
                personid = vipid != -1 ? vipid : personid;
            } else if (
                p[i].vip) {  // 虽然当前的最早空闲且号最小的桌子不是vip，但是还可能存在同时空闲，桌号更大的桌子是vip
                for (int j = 0; j < k; j++) {
                    if (t[j].vip && t[j].endtime <= p[personid].arrive) {
                        tableid = j;
                        break;
                    }
                }
            }  // 如果当前的桌子非vip，且当前的序列的第一个玩家对非vip，顺序选择即可，换句话说，personId和tableId无需调整
        } else {
            /*
                           如果当前的最早空闲的桌子空闲时，没有玩家在等待序列中，即当一个玩家到达时，应该是至少有一个桌子是空闲的
                           我们总是希望选择空闲中的桌子中桌子号最小的，如果到达了一个vip玩家对，并且存在空闲的vip桌子，我们选择空闲中的vip桌中号最小的
                           在这里，我们不管是否是vip，先得到空闲中的桌子中桌子号最小的，如果当前到达的玩家对未vip，并且存在空闲的vip桌子，
                           我们用空闲中的vip桌中号最小的那个桌子覆盖之前得到的tableId
           */
            for (int j = 0; j < k; j++) {
                if (t[j].endtime <= p[personid].arrive) {
                    tableid = j;
                    break;
                }
            }
            if (p[personid].vip) {
                for (
                    int j = 0; j < k;
                    j++) {  // 尝试寻找空闲的vip桌子并调整tableId，顺序找到即退出得到的就是号码最小的
                    if (t[j].vip && t[j].endtime <= p[personid].arrive) {
                        tableid = j;
                        break;
                    }
                }
            }
        }
        update(personid, tableid);
        while (i < p.size() && p[i].served) i++;
    }
    sort(p.begin(), p.end(), cmp2);
    for (int i = 0; i < p.size(); i++) {
        if (p[i].served) {
            int wait = p[i].start - p[i].arrive;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p[i].arrive / 3600,
                   p[i].arrive % 3600 / 60, p[i].arrive % 60, p[i].start / 3600,
                   p[i].start % 3600 / 60, p[i].start % 60,
                   (int)(1.0 * wait / 60 + 0.5));
        }
    }
    for (int i = 0; i < k; i++) {
        if (i != 0) printf(" ");
        printf("%d", t[i].num);
    }
    return 0;
}