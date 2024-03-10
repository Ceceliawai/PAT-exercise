#include <algorithm>
#include <iostream>
using namespace std;
typedef struct RBNode {
    int key;
    struct RBNode* left;
    struct RBNode* right;
} node;
int preorder[32];
int fabs(int x) { return x > 0 ? x : -x; }
node* buildTree(int l, int r) {
    node* n = new node;
    n->key = preorder[l];
    if (l == r) {
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    int root = n->key;
    int i;
    for (i = l + 1; i <= r; i++) {
        if (fabs(preorder[i]) > fabs(root)) break;
    }
    int left = i - l - 1;
    int right = r - i + 1;
    if (left == 0)
        n->left = NULL;
    else
        n->left = buildTree(l + 1, i - 1);
    if (right == 0)
        n->right = NULL;
    else
        n->right = buildTree(i, r);
    return n;
}
int getbh(node* T) {
    if (T == NULL) return 0;
    int a = getbh(T->left);
    int b = getbh(T->right);
    return T->key < 0 ? max(a, b) : max(a, b) + 1;
}
bool judge1(node* T) {
    if (T == NULL) return true;
    // negative用于表示红结点
    if (T->key < 0) {
        // 判断两个孩子
        if (T->left != NULL && T->left->key < 0) return false;
        if (T->right != NULL && T->right->key < 0) return false;
    }
    return judge1(T->left) && judge1(T->right);
}
bool judge2(node* T) {
    if (T == NULL) return true;
    int a = getbh(T->left);
    int b = getbh(T->right);
    if (a != b) return false;
    return judge2(T->left) && judge2(T->right);
}
int main() {
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> preorder[i];
        node* T = buildTree(0, N - 1);
        if (T == NULL)
            cout << "Yes" << endl;
        else {
            bool f1 = judge1(T);
            bool f2 = judge2(T);
            if (T->key < 0 || !f1 || !f2)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}