#include <algorithm>
#include <iostream>
using namespace std;
char mydata[22][11];
int v[22][2];
bool e[22];
int N;
int root;
void inorder(int n) {
    if (n != root && (v[n][0] != -1 || v[n][1] != -1)) cout << "(";
    if (v[n][0] != -1) inorder(v[n][0]);
    cout << mydata[n];
    if (v[n][1] != -1) inorder(v[n][1]);
    if (n != root && (v[n][0] != -1 || v[n][1] != -1)) cout << ")";
    return;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> mydata[i];
        cin >> v[i][0];
        if (v[i][0] != -1) e[v[i][0]] = true;
        cin >> v[i][1];
        if (v[i][1] != -1) e[v[i][1]] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (e[i] == false) {
            root = i;
            break;
        }
    }
    inorder(root);
    return 0;
}