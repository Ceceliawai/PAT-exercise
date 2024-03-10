#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef struct Edge {
    int a;
    int b;
} edge;
vector<edge> e;
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        edge newe;
        newe.a = x;
        newe.b = y;
        e.push_back(newe);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        set<int> v;
        for (int j = 0; j < K; j++) {
            int id;
            cin >> id;
            v.insert(id);
        }
        bool flag = true;
        for (int j = 0; j < e.size(); j++) {
            int x = e[j].a;
            int y = e[j].b;
            if (v.count(x) == 0 && v.count(y) == 0) {
                flag = false;
                break;
            }
        }
        if (flag == false)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}