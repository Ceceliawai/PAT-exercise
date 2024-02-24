#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int ids[100010];
int T[100010];
int V[100010];
vector<int> sage;
vector<int> noble;
vector<int> small;
vector<int> fool;
int N, L, H;
bool mycmp(int a, int b) {
    if (V[a] + T[a] != V[b] + T[b]) return V[a] + T[a] > V[b] + T[b];
    if (V[a] != V[b]) return V[a] > V[b];
    return ids[a] < ids[b];
}
int main() {
    cin >> N >> L >> H;
    L = max(L, 60);
    H = min(H, 99);
    for (int i = 0; i < N; i++) {
        cin >> ids[i] >> V[i] >> T[i];
        if (T[i] >= L && V[i] >= L) {
            if (T[i] >= H && V[i] >= H)
                sage.push_back(i);
            else if (T[i] < H && V[i] >= H)
                noble.push_back(i);
            else if (V[i] < H && T[i] < H && V[i] >= T[i])
                fool.push_back(i);
            else {
                small.push_back(i);
            }
        }
    }
    cout << sage.size() + noble.size() + small.size() + fool.size();
    cout << endl;
    sort(sage.begin(), sage.end(), mycmp);
    sort(noble.begin(), noble.end(), mycmp);
    sort(small.begin(), small.end(), mycmp);
    sort(fool.begin(), fool.end(), mycmp);
    for (int i = 0; i < sage.size(); i++) {
        int index = sage[i];
        printf("%08d", ids[index]);
        cout << " " << V[index] << " " << T[index] << endl;
    }
    for (int i = 0; i < noble.size(); i++) {
        int index = noble[i];
        printf("%08d", ids[index]);
        cout << " " << V[index] << " " << T[index] << endl;
    }
    for (int i = 0; i < fool.size(); i++) {
        int index = fool[i];
        printf("%08d", ids[index]);
        cout << " " << V[index] << " " << T[index] << endl;
    }
    for (int i = 0; i < small.size(); i++) {
        int index = small[i];
        printf("%08d", ids[index]);
        cout << " " << V[index] << " " << T[index] << endl;
    }

    return 0;
}