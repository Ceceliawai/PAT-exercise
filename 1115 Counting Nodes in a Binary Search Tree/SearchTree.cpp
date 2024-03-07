#include <algorithm>
#include <iostream>
using namespace std;
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} node;
int d[1010], maxd = 0;
void dfs(node* root, int depth) {
    if (root == NULL) return;
    maxd = max(depth, maxd);
    d[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
node* insert(node* root, int val) {
    if (root == NULL) {
        node* n = new node;
        n->key = val;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (val > root->key) {
        root->right = insert(root->right, val);
    } else if (val <= root->key) {
        root->left = insert(root->left, val);
    }
    return root;
}
int main() {
    int N;
    cin >> N;
    node* T = NULL;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        T = insert(T, num);
    }
    fill(d, d + 1010, 0);
    // dfs，记录每一个高度的结点个数
    dfs(T, 0);
    cout << d[maxd] << " + " << d[maxd - 1] << " = " << d[maxd - 1] + d[maxd];
    return 0;
}