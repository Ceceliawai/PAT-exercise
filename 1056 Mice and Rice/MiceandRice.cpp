#include <iostream>
#include <vector>
using namespace std;
typedef struct Mice {
    int rank;
    int weight;
} mice;
vector<mice> allmice;
vector<int> remain;
vector<int> temp;
int main() {
    int Np, Ng, order, curmax, groups, preid, curcount = 0;
    cin >> Np >> Ng;
    Ng = min(Ng, 1000);
    for (int i = 0; i < Np; i++) {
        mice nm;
        cin >> nm.weight;
        allmice.push_back(nm);
    }
    for (int i = 0; i < Np; i++) {
        cin >> order;
        remain.push_back(order);  // 初始序列
    }
    while (remain.size() != 1) {
        // 比赛逻辑
        groups = remain.size() % Ng == 0 ? remain.size() / Ng
                                         : remain.size() / Ng + 1;
        // 输了的rank=groups+1
        curmax = remain[0];
        curcount = 1;
        temp.push_back(curmax);
        for (int i = 1; i < remain.size(); i++) {  // 遍历所有还没比赛的老鼠
            curcount++;
            if (curcount > Ng) {
                curcount = 1;
                curmax = remain[i];
                temp.push_back(remain[i]);
                continue;
            }
            if (allmice[remain[i]].weight > allmice[curmax].weight) {
                preid = temp[temp.size() - 1];
                temp.pop_back();
                allmice[preid].rank = groups + 1;
                curmax = remain[i];  // 因为少了这个所以14测试点没过
                temp.push_back(remain[i]);
            } else {
                allmice[remain[i]].rank = groups + 1;
            }
        }
        remain = temp;
        temp.clear();
    }
    if (remain.size() == 1) allmice[remain[0]].rank = 1;
    for (int i = 0; i < Np; i++) {
        if (i != 0) cout << " ";
        cout << allmice[i].rank;
    }
    return 0;
}