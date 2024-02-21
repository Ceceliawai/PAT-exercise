#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[110];
int N, W, M, S, K, id, curid, w[110], curw = 0;
vector<int> temp;
vector< vector<int> > res;
bool mycmp(vector<int>v1,vector<int>v2){
    int length=min(v1.size(),v2.size());
    for(int i=1;i<length;i++){
        if(v1[i]!=v2[i])return v1[i]>v2[i];
    }
}
void dfs(int root) {
    temp.push_back(w[root]);
    curw += w[root];
    if (adj[root].size() == 0 && curw == S) {
        res.push_back(temp);
        temp.pop_back();
        curw -= w[root];
        return;
    }
    else if(adj[root].size() == 0 && curw != S){
        temp.pop_back();
        curw -= w[root];
        return;
	}
    if (curw >= S) {
        temp.pop_back();
        curw -= w[root];
        return;
    }
    for (int i = 0; i < adj[root].size(); i++) {
        dfs(adj[root][i]);
    }
    temp.pop_back();
    curw -= w[root];
    return;
}
int main() {
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> id >> K;
        for (int j = 0; j < K; j++) {
            cin >> curid;
            adj[id].push_back(curid);
        }
    }
    dfs(0);
    sort(res.begin(),res.end(),mycmp);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            if (j != 0) cout << " ";
            cout << res[i][j];
        }
        cout << endl;
    }
}
