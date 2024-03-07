#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef struct Family {
    int id;
    int member;
    double avgs;
    double avga;
} family;
int e[10000][2];       // 记录他的父母 0for father 1 for mother
vector<int> v[10000];  // 记录他的孩子
set<int> myp;
set<int> mychild[10000];
vector<family> flist;
int en[10000], ea[10000];
bool visited[10000];
int N;
int FID, FM;
double totals, totala;
void dfs(int root) {
    FM++;
    visited[root] = true;
    if (root < FID) {
        FID = root;
    }
    totals += en[root];
    totala += ea[root];
    if (e[root][0] != -1) {
        if (visited[e[root][0]] == false) {
            dfs(e[root][0]);
        }
    }
    if (e[root][1] != -1) {
        if (visited[e[root][1]] == false) {
            dfs(e[root][1]);
        }
    }
    for (int c : mychild[root]) {
        if (visited[c] == false) {
            dfs(c);
        }
    }
    return;
}
bool mycmp(family f1, family f2) {
    if (f1.avga != f2.avga) return f1.avga > f2.avga;
    return f1.id < f2.id;
}
int main() {
    cin >> N;
    int id, father, mother, k, child, sets, area;
    fill(e[0], e[0] + 10000 * 2, -1);
    fill(en, en + 10000, 0);
    fill(ea, ea + 10000, 0);
    for (int i = 0; i < N; i++) {
        cin >> id >> father >> mother >> k;
        myp.insert(id);
        e[id][0] = father;
        e[id][1] = mother;
        if (father != -1) {
            myp.insert(father);
            mychild[father].insert(id);
        }
        if (mother != -1) {
            myp.insert(mother);
            mychild[mother].insert(id);
        }
        for (int j = 0; j < k; j++) {
            cin >> child;
            mychild[id].insert(child);
            if (e[child][0] == -1)
                e[child][0] = id;
            else
                e[child][1] = id;
        }
        cin >> sets >> area;
        en[id] = sets;
        ea[id] = area;
    }
    fill(visited, visited + 10000, false);
    int cnt = 0;
    for (int c : myp) {
        if (visited[c] == false) {
            FID = 10000;
            FM = 0;
            totals = 0;
            totala = 0;
            dfs(c);
            family newf;
            newf.id = FID;
            newf.member = FM;
            newf.avgs = (double)totals * 1.0 / FM;
            newf.avga = totala * 1.0 / FM;
            flist.push_back(newf);
        }
    }
    sort(flist.begin(), flist.end(), mycmp);
    cout << flist.size() << endl;
    for (int i = 0; i < flist.size(); i++) {
        printf("%04d %d %.3f %.3f\n", flist[i].id, flist[i].member,
               flist[i].avgs, flist[i].avga);
    }
}