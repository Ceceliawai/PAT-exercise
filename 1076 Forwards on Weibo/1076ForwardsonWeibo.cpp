/*
其实应该是BFS，我写的DFS，所以超时了，然后第二个点也没过不知道为什么
改成vector了，不超时，但还是错了，说明肯定哪里有点问题：原来是set没清空。。。
你犯的都是什么低级错误，我真的服了你
但总体其实就是一个有向图的问题
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int L, N, K, cnt = 0;
vector<int> query;
set<int> myset;
vector<int> fans[1010];
bool visited[1010];
void dfs(int root, int depth) {
    if (depth >= L) return;  // 超出被计算的范围
    visited[root] = true;
    for (int j = 0; j < fans[root].size(); j++) {
        int i = fans[root][j];
        if (visited[i] == false) {
            dfs(i, depth + 1);
            myset.insert(i);
        }
    }
    return;
}
int main() {
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int y;
            cin >> y;
            fans[y].push_back(i);
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        query.push_back(num);
    }
    for (int i = 0; i < K; i++) {
        int root = query[i];
        cnt = 0;
        fill(visited, visited + 1010, false);
        myset.clear();
        dfs(root, 0);
        cout << myset.size() << endl;
    }
}