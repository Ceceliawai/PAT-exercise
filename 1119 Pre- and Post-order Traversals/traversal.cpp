#include <iostream>
#include <vector>
using namespace std;
int preorder[31], postorder[31];
typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} node;
bool flag = true;
int N, cnt = 0;
vector<int> output;
void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    if (root->left != NULL && root->right == NULL) flag = false;
    if (root->left == NULL && root->right != NULL) flag = false;
    output.push_back(root->key);
    inorder(root->right);
    return;
}
node *buildTree(int prel, int prer, int posl, int posr) {
    node *n = new node;
    n->key = preorder[prel];
    if (prel + 1 >= N) {
        // 没有子树了，这是个叶子节点
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (prel == prer) {
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    int root = preorder[prel + 1];
    int j;
    for (j = posl; j <= posr; j++) {
        if (postorder[j] == root) break;
    }
    int left = j - posl + 1;
    int right = posr - j - 1;
    if (left == 0) {
        flag = false;
        n->left = NULL;
    } else {
        n->left = buildTree(prel + 1, prel + left, posl, posl + left - 1);
    }
    if (right == 0) {
        flag = false;
        n->right = NULL;
    } else {
        n->right = buildTree(prel + left + 1, prer, j + left, prer - 1);
    }
    return n;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> preorder[i];
    for (int i = 0; i < N; i++) cin >> postorder[i];
    node *T = NULL;
    T = buildTree(0, N - 1, 0, N - 1);
    flag = true;
    inorder(T);
    if (flag == false) {
        cout << "No" << endl;
    } else
        cout << "Yes" << endl;
    for (int i = 0; i < output.size(); i++) {
        if (i != 0) cout << " ";
        cout << output[i];
    }
    cout << endl;
    return 0;
}