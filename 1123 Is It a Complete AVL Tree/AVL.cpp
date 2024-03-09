#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
} node;
int getHeight(node *root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
// 向右旋转
node *rotateR(node *root) {
    node *left = root->left;
    root->left = left->right;
    left->right = root;
    return left;
}
// 向左旋转
node *rotateL(node *root) {
    node *right = root->right;
    root->right = right->left;
    right->left = root;
    return right;
}
// 先右再左
node *rotateRL(node *root) {
    root->right = rotateR(root->right);
    return rotateL(root);
}
// 先左再右
node *rotateLR(node *root) {
    root->left = rotateL(root->left);
    return rotateR(root);
}
node *insert(node *root, int val) {
    if (root == NULL) {
        node *n = new node;
        n->key = val;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (val > root->key)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);

    // 插入完了之后逐层向上调整
    if (getHeight(root->left) - getHeight(root->right) == 2) {
        // 左边比右边多了，比较当前插入的值和root->left的值的关系
        if (val > root->left->key) {
            root = rotateLR(root);
        } else
            root = rotateR(root);
    }
    if (getHeight(root->left) - getHeight(root->right) == -2) {
        if (val > root->right->key) {
            root = rotateL(root);
        } else
            root = rotateRL(root);
    }
    return root;
}
int main() {
    int N;
    cin >> N;
    node *T = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        T = insert(T, x);
    }
    queue<node *> q;
    q.push(T);
    bool flag = true;
    bool isLeft = false;
    bool meetnull = false;
    int cnt = 0;
    while (q.empty() == false) {
        node *root = q.front();
        q.pop();
        if (root != NULL) {
            if (cnt != 0) cout << " ";
            cout << root->key;
            cnt++;
        }
        if (root == NULL) {
            meetnull = true;
            continue;
        }
        if (meetnull == true && root != NULL) {
            flag = false;
        }
        if (root->left == NULL && root->right != NULL) {
            flag = false;
        }
        if (isLeft == true) {
            if (root->left != NULL || root->right != NULL) flag = false;
        }
        if (root->left != NULL && root->right == NULL) {
            isLeft = true;
        }
        if (root != NULL) {
            q.push(root->left);
            q.push(root->right);
        }
    }
    cout << endl;
    if (flag == false)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}