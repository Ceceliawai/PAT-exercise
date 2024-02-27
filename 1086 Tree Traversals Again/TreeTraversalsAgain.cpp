#include <iostream>
#include <string>
using namespace std;
int S[30], N, top = -1;
int inorder[30], preorder[30], postorder[30];
// 左右中 中左右 左右中
int innt = 0;
int pnt = 0;
int cnt = 0;  // 用来记录已经输出的结点个数，方便实现点之间的空格输出
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;
node* build(int il, int ir, int pl, int pr) {
    if (il > ir || pl > pr) return NULL;
    int root = pl;
    int index = -1;
    // 找到当前的root
    for (int i = il; i <= ir; i++) {
        if (inorder[i] == preorder[root]) {
            index = i;
            break;
        }
    }
    int leng = index - il - 1;
    node* n = new node;
    n->data = preorder[root];
    n->left = build(il, il + leng, pl + 1, pl + leng + 1);
    n->right = build(index + 1, ir, pl + leng + 2, pr);
    return n;
}
void posttravel(node* root) {
    if (root == NULL) return;
    posttravel(root->left);
    posttravel(root->right);
    if (cnt != 0) cout << " ";
    cout << root->data;
    cnt++;
}
int main() {
    cin >> N;
    string str;
    int key;
    for (int i = 0; i < 2 * N; i++) {
        cin >> str;
        if (str == "Push") {
            cin >> key;
            preorder[pnt++] = key;  // pre是入栈顺序
            S[++top] = key;
        } else {
            key = S[top--];
            inorder[innt++] = key;  // in是出栈顺序
        }
    }
    node* root = build(0, N - 1, 0, N - 1);  // 建立树
    posttravel(root);                        // 后序遍历
}