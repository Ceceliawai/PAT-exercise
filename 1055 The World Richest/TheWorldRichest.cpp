/*  题目时间限制其实很宽泛，所以没必要自己实现heap，用algorithm和vector实现堆的功能就完事了
    好像也不是很宽泛，还是有一个测试点过不去，不知道该怎么办了
 */
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char names[100010][9];
vector<int> MyHeap;
vector<vector<int>> res;
int N, K, M, Amin, Amax, ages[100010], wealth[100010];
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
        scanf("%d %d %d", &M, &Amin, &Amax);
        // cin >> M >> Amin >> Amax;
        MyHeap.clear();
        for (int j = 0; j < N; j++) {
            if (ages[j] >= Amin && ages[j] <= Amax) {
                if (MyHeap.size() < M) {
                    MyHeap.push_back(j);
                    sort(MyHeap.begin(), MyHeap.end(), mycmp);
                } else {
                    if (mycmp(j, MyHeap[MyHeap.size() - 1]) == true) {
                        // j应该排在最后一个前面，说明最后一个被挤出去了
                        MyHeap[MyHeap.size() - 1] = j;
                        sort(MyHeap.begin(), MyHeap.end(), mycmp);
                    }
                }
            }
        }
        res.push_back(MyHeap);
    }
    for (int i = 0; i < K; i++) {
        cout << "Case #" << i + 1 << ":" << endl;
        if (res[i].size() == 0) {
            cout << "None" << endl;
        } else {
            for (int j = 0; j < res[i].size(); j++) {
                // cout << names[res[i][j]] << " " << ages[res[i][j]] << " "<<
                // wealth[res[i][j]] << endl;
                printf("%s %d %d\n", names[res[i][j]], ages[res[i][j]],
                       wealth[res[i][j]]);
            }
        }
    }
    return 0;
}