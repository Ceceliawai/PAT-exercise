#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 先根据inorder和postorder建立树，然后层次遍历，每一层的结点存在一个vector里
// 然后遍历输出每一层的结点，用一个flag控制是正向还是反向。
typedef struct Node {
    int key;
    int depth;
    struct Node *left;
    struct Node *right;
} node;
int inorder[31], postorder[31], N;
vector<int> v[31];
int maxd = 0;
node *buildTree(int il, int ir, int pl, int pr, int depth) {
    maxd = max(depth, maxd);
    int root = postorder[pr];
    node *n = new node;
    n->depth = depth;
    n->key = root;
    int j;
    for (j = il; j <= ir; j++) {
        if (inorder[j] == root) break;
    }
    int left = j - il;
    int right = ir - j;
    if (left == 0)
        n->left = NULL;
    else {
        n->left = buildTree(il, j - 1, pl, pl + left - 1, depth + 1);
    }
    if (right == 0)
        n->right = NULL;
    else {
        n->right = buildTree(j + 1, ir, pl + left, pr - 1, depth + 1);
    }
    return n;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> inorder[i];
    for (int i = 0; i < N; i++) cin >> postorder[i];
    node *T = buildTree(0, N - 1, 0, N - 1, 0);
    queue<node *> q;
    q.push(T);
    while (q.empty() == false) {
        node *root = q.front();
        q.pop();
        v[root->depth].push_back(root->key);
        if (root->left != NULL) q.push(root->left);
        if (root->right != NULL) q.push(root->right);
    }
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i <= maxd; i++) {
        if (flag == false) {
            for (int j = 0; j < v[i].size(); j++) {
                if (cnt != 0) cout << " ";
                cout << v[i][j];
                cnt++;
            }
            flag = true;
        } else if (flag == true) {
            for (int j = v[i].size() - 1; j >= 0; j--) {
                if (cnt != 0) cout << " ";
                cout << v[i][j];
                cnt++;
            }
            flag = false;
        }
    }
    return 0;
}