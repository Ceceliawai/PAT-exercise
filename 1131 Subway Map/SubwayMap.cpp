#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int e[10000][10000], S, D;
vector<int> v[10000];
int cnt = 0;
vector<int> temp;
vector<int> res;
int rescnt = (0x1) << 30;
bool flag = false;
int gettransfer(vector<int> path) {
    int curline = -1;
    int pre = S;
    int transfer = 0;
    for (int i = 1; i < path.size(); i++) {
        int preid = path[i - 1];
        int curid = path[i];
        if (curline == -1) {
            curline = e[preid][curid];
        } else {
            if (curline != e[preid][curid]) {
                // 换站点了
                curline = e[preid][curid];
                pre = preid;
                transfer++;
            }
        }
        if (i == path.size() - 1) {
            // 结尾输出
            transfer++;
        }
    }
    return transfer;
}
void dfs(int root) {
    cnt++;
    temp.push_back(root);
    if (root == D) {
        if (cnt < rescnt) {
            res = temp;
            rescnt = cnt;
        } else if (cnt == rescnt) {
            if (gettransfer(temp) < gettransfer(res)) {
                res = temp;
            }
        }
        temp.pop_back();
        cnt--;
        return;
    }
    for (int i = 0; i < v[root].size(); i++) {
        if (count(temp.begin(), temp.end(), v[root][i]) == 0) {
            dfs(v[root][i]);
        }
    }
    cnt--;
    temp.pop_back();
}
int main() {
    int M;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        int K;
        cin >> K;
        int pre;
        cin >> pre;
        for (int j = 1; j < K; j++) {
            int id;
            cin >> id;
            e[pre][id] = i;
            e[id][pre] = i;
            v[pre].push_back(id);
            v[id].push_back(pre);
            pre = id;
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> S >> D;
        temp.clear();
        flag = false;
        cnt = 0;
        res.clear();
        rescnt = (0x1) << 30;
        dfs(S);
        cout << rescnt - 1 << endl;
        int curline = -1;
        int pre = S;
        for (int i = 1; i < res.size(); i++) {
            int preid = res[i - 1];
            int curid = res[i];
            if (curline == -1) {
                curline = e[preid][curid];
            } else {
                if (curline != e[preid][curid]) {
                    // 换站点了
                    printf("Take Line#%d from %04d to %04d.\n", curline, pre,
                           preid);
                    curline = e[preid][curid];
                    pre = preid;
                }
            }
            if (i == res.size() - 1) {
                // 结尾输出
                printf("Take Line#%d from %04d to %04d.\n", curline, pre,
                       curid);
            }
        }
    }
    return 0;
}