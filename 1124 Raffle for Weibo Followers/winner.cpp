#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
int M, N, S;
int main() {
    cin >> M >> N >> S;
    vector<string> list;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        list.push_back(name);
    }
    int cnt = 0;
    set<string> win;
    for (int i = S - 1; i < list.size(); i = i + N) {
        while (win.count(list[i]) != 0) i++;
        cout << list[i] << endl;
        win.insert(list[i]);
        cnt++;
    }
    if (cnt == 0) cout << "Keep going...";
}