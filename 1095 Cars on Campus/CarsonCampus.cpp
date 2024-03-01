#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef struct Car {
    int intime = -1;
    int outime = -1;
    string id;
} car;
typedef struct Record {
    int time;
    string id;
    int status;
} record;
map<string, int> idtoindex;
int mnt = 0;
vector<record> reclist;
vector<int> query;
int N, K, H, M, S, t;
int carin[86400], carout[86400];
int mcount[86400];
int mtime[86400];
int maxt = -1;
vector<string> res;
int gettime(int H, int M, int S) { return (H * 60 + M) * 60 + S; }
bool mycmp(record r1, record r2) {
    if (r1.id != r2.id) return r1.id < r2.id;
    return r1.time < r2.time;
}
int main() {
    cin >> N >> K;
    fill(carin, carin + 86400, 0);
    fill(carout, carout + 86400, 0);
    fill(mtime, mtime + 86400, 0);
    for (int i = 0; i < N; i++) {
        string id, s;
        cin >> id;
        scanf("%d:%d:%d", &H, &M, &S);
        t = gettime(H, M, S);
        cin >> s;
        record r;
        r.id = id;
        r.time = t;
        r.status = s == "in" ? 1 : 0;
        reclist.push_back(r);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d:%d:%d", &H, &M, &S);
        t = gettime(H, M, S);
        query.push_back(t);
    }
    sort(reclist.begin(), reclist.end(), mycmp);
    record pre, cur;
    pre.time = -1;  // initial
    for (int i = 0; i < reclist.size(); i++) {
        cur = reclist[i];
        if (cur.status == 0) {  // 遇到一个出去的
            if (pre.status == 1 && pre.time != -1 && pre.id == reclist[i].id) {
                // 前面有配套的in
                carin[pre.time]++;
                if (idtoindex.count(cur.id) == 0) {
                    idtoindex[cur.id] = mnt;
                    mnt++;
                }
                carout[cur.time]++;
                mtime[idtoindex[cur.id]] += cur.time - pre.time;
                t = mtime[idtoindex[cur.id]];
                if (t > maxt) {
                    maxt = t;
                    res.clear();
                    res.push_back(cur.id);
                } else if (t == maxt) {
                    res.push_back(cur.id);
                }
            }
        }
        pre = cur;
    }
    int cnt = 0;
    for (int Time = 0; Time < 86400; Time++) {
        if (carin[Time] != 0) cnt += carin[Time];  // 进入了一辆车
        if (carout[Time] != 0) cnt -= carout[Time];
        mcount[Time] = cnt;
    }
    for (int i = 0; i < query.size(); i++) {
        cout << mcount[query[i]] << endl;
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        cout << " ";
    }
    S = maxt % 60;
    maxt /= 60;
    M = maxt % 60;
    maxt /= 60;
    H = maxt % 24;
    printf("%02d:%02d:%02d", H, M, S);
    return 0;
}