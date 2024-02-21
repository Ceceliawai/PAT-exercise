#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char names[100010][9];
vector<int> MyHeap;
vector<vector<int>> res;
int N, K, M[10010], Amin, Amax, ages[100010],
    wealth[100010];  // 特别好。。这样写内存超限了
// 解决方法就是把node变成vector就好了，不要太思维固化在那个Heap的模式里面就得了
bool mycmp(int a, int b) {
    if (wealth[a] != wealth[b]) return wealth[a] > wealth[b];
    if (ages[a] != ages[b]) return ages[a] < ages[b];
    return strcmp(names[a], names[b]) < 0;
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        // cin >> names[i] >> ages[i] >> wealth[i];
        scanf("%s %d %d", names[i], &ages[i], &wealth[i]);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d", &M[i], &Amin, &Amax);
        // cin >> M >> Amin >> Amax;
        MyHeap.clear();
        for (int j = 0; j < N; j++) {
            if (ages[j] >= Amin && ages[j] <= Amax) {
                MyHeap.push_back(j);
            }
        }
        res.push_back(MyHeap);
    }
    for (int i = 0; i < K; i++) {
        cout << "Case #" << i + 1 << ":" << endl;
        if (res[i].size() == 0) {
            cout << "None" << endl;
        } else {
            sort(res[i].begin(), res[i].end(), mycmp);
            for (int j = 0; j < M[i] && j < res[i].size(); j++) {
                // cout << names[res[i][j]] << " " << ages[res[i][j]] << " "<<
                // wealth[res[i][j]] << endl;
                printf("%s %d %d\n", names[res[i][j]], ages[res[i][j]],
                       wealth[res[i][j]]);
            }
        }
    }
    return 0;
}