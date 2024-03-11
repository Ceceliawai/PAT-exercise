#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int P;  // 作业
int M;  // 期中考试
int N;  // 期末考试
int Gp[30010], Gm[30010], Gf[30010], G[30010];
map<string, int> toindex;
vector<string> list;
int getG(int a, int b) {
    if (a == -1 && b == -1) return 0;
    if (a == -1 && b != -1) return b;
    if (a != -1 && b == -1) return a * 0.4 + 0.5;
    if (a > b) return a * 0.4 + b * 0.6 + 0.5;
    return b;
}
bool mycmp(string a, string b) {
    int ia = toindex[a];
    int ib = toindex[b];
    if (G[ia] != G[ib]) return G[ia] > G[ib];
    return a < b;
}
int main() {
    fill(Gp, Gp + 30010, -1);
    fill(Gm, Gm + 30010, -1);
    fill(Gf, Gf + 30010, -1);
    cin >> P >> M >> N;
    int cnt = 0;
    for (int i = 0; i < P; i++) {
        string name;
        cin >> name;
        int index;
        if (toindex.count(name) == 0) {
            toindex[name] = cnt;
            list.push_back(name);
            index = cnt;
            cnt++;
        } else
            index = toindex[name];
        cin >> Gp[index];
    }
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        int index;
        if (toindex.count(name) == 0) {
            toindex[name] = cnt;
            list.push_back(name);
            index = cnt;
            cnt++;
        } else
            index = toindex[name];
        cin >> Gm[index];
    }
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        int index;
        if (toindex.count(name) == 0) {
            toindex[name] = cnt;
            list.push_back(name);
            index = cnt;
            cnt++;
        } else
            index = toindex[name];
        cin >> Gf[index];
    }
    vector<string> res;
    for (int i = 0; i < list.size(); i++) {
        string name = list[i];
        int index = toindex[list[i]];
        int score = getG(Gm[index], Gf[index]);
        G[index] = score;
        if (Gp[index] >= 200 && G[index] >= 60) res.push_back(name);
    }
    if (res.size() == 1) {
        int index = toindex[res[0]];
        cout << res[0] << " " << Gp[index] << " " << Gm[index] << " "
             << Gf[index] << " " << G[index] << endl;
        return 0;
    }
    sort(res.begin(), res.end(), mycmp);
    for (int i = 0; i < res.size(); i++) {
        int index = toindex[res[i]];
        cout << res[i] << " " << Gp[index] << " " << Gm[index] << " "
             << Gf[index] << " " << G[index] << endl;
    }
    return 0;
}