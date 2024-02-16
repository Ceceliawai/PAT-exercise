#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// 本来这里只有一个int，但我为了区分是什么就分开写了
int n, m, k;  // number of customers//number of tables//number of VIP tables
int H, M, S;  // Hour//Minute//Second
int t, table, vtable;
int cnt, now, nowt;  // 1//现在的客人//现在使用的桌子
int T[100000], V[100000];  // 要玩的时间 是否为VIP//客户//index为到达的时间
int num[10001];
int AnsI[10001], AnsO[10001], vip[10001];  // 1//2//第index个桌子是否为VIP桌子
map<int, int> Table;                       // index//还需要被占用的时间
queue<int> Wait, vWait;  // 普通等待序列//VIP等待序列
int main() {
    scanf("%d", &n);  // 输入客人的数目
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d", &H, &M, &S);  // 到达时间
        t = H * 3600 + M * 60 + S;      // 计算成秒（用秒存储时间）
        scanf("%d %d", &T[t], &V[t]);   // 存储需要的时间，是否为VIP
        T[t] = min(T[t], 120) * 60;     // 最多玩2小时，换算成秒
    }
    scanf("%d %d", &m, &k);  // 输入桌子的个数
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);  // VIP桌子的编号
        vip[t] = 1;
    }
    for (int Time = 28800; Time < 75600; Time++, table = vtable = now = 0) {
        // 28800=8*60*60，每次更新一秒
        // 每次从table0开始判断是否空闲
        if (T[Time] && V[Time])            // 还要玩，且是VIP
            vWait.push(Time);              // 放到vip的等待队列
        else if (T[Time])                  // 还要玩，不是VIP
            Wait.push(Time);               // 放到普通的等待序列
        for (int i = 1; i <= m; i++) {     // 桌子从1开始编号
            if (Table[i] > 0) Table[i]--;  // 桌子还需要被占用的时间-1s
            if (Table[i] == 0 && vip[i] && vtable == 0)  // 此刻释放的vtable
                vtable = i;
            if (Table[i] == 0 && table == 0)  // 此刻释放的非viptable
                table = i;
        }
        if (!vWait.empty() &&
            (table || vtable)) {  // 先安排到了的vip客户到vtable
            now = vWait.front();  // queue头
            nowt = vtable;
            if (vtable != 0)  // 有空闲的vtable
                vWait.pop();  // 分配了
            else {
                nowt = table;  // 按照到达时间分配
                if (!Wait.empty() &&
                    Wait.front() < vWait.front()) {  // 到达时间
                    // 非VIP客人先到了，得先给非VIP客人
                    now = Wait.front();
                    Wait.pop();
                } else
                    vWait.pop();
            }
        } else if (!Wait.empty() && (table || vtable)) {
            // 没有VIP客人，分配给非VIP客人
            if (table != 0)  // 优先分配非VIP桌子
                nowt = table;
            else
                nowt = vtable;
            now = Wait.front();
            Wait.pop();
        }
        if (now == 0) continue;  // 没有客人被服务
        Table[nowt] = T[now];  // 更新被占用的table还需要被占用的时间
        AnsI[cnt] = now;       // 按被服务顺序排列的客人的index
        AnsO[cnt++] = Time;  // 此客人被服务的时间
        num[nowt]++;         // 更新table服务的客人数
    }
    for (int i = 0; i < cnt; i++)
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", AnsI[i] / 3600,
               AnsI[i] % 3600 / 60, AnsI[i] % 60, AnsO[i] / 3600,
               AnsO[i] % 3600 / 60, AnsO[i] % 60,
               (AnsO[i] - AnsI[i] + 30) / 60);
    for (int i = 1; i <= m; i++) {
        if (i != 1) printf(" ");
        printf("%d", num[i]);
    }
    return 0;
}