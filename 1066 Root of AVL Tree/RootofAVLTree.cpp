#include <iostream>
using namespace std;
typedef struct AVLNode {
    int num;
    struct AVLNode* left;
    struct AVLNode* right;
} node;
node* rotateRight(node* root) {
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node* rotateLeft(node* root) {
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node* rotateLeftRight(node* root) {
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
    return root;
}
node* rotateRightLeft(node* root) {
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
    return root;
}
int GetHeight(node* root) {
    if (root == NULL) return 0;
    return max(GetHeight(root->left), GetHeight(root->right)) + 1;
}
node* Insert(node* root, int num) {
    if (root == NULL) {
        node* nn = new node;
        nn->num = num;
        nn->left = NULL;
        nn->right = NULL;
        root = nn;
        return root;
    }
    if (root->num > num) {
        root->left = Insert(root->left, num);
        if (GetHeight(root->left) - GetHeight(root->right) == 2) {
            if (num < root->left->num) {
                root = rotateRight(root);
            } else
                root = rotateLeftRight(root);
        }
        return root;
    }
    if (root->num < num) {
        root->right = Insert(root->right, num);
        if (GetHeight(root->right) - GetHeight(root->left) == 2) {
            if (num > root->right->num) {
                root = rotateLeft(root);
            } else
                root = rotateRightLeft(root);
        }
        return root;
    }
    return root;
}
int main() {
    int N, num;
    cin >> N;
    node* T = NULL;
    for (int i = 0; i < N; i++) {
        cin >> num;
        T = Insert(T, num);
    }
    cout << T->num;
    return 0;
}