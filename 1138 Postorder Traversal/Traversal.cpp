#include <iostream>
using namespace std;
int preorder[50010], inorder[50010];
int findFirst(int il, int ir, int pl, int pr) {
    int root = preorder[pl];
    if (il == ir) return root;  // 叶子结点
    int j;
    for (j = il; j <= ir; j++) {
        if (inorder[j] == root) break;
    }
    int left = j - il;
    if (left == 0) {
        // 去找右子树的最左
        return findFirst(j + 1, ir, pl + left + 1, pr);
    } else {
        // 继续找左子树
        return findFirst(il, j - 1, pl + 1, pl + left);
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> preorder[i];
    for (int i = 0; i < N; i++) cin >> inorder[i];
    int res = findFirst(0, N - 1, 0, N - 1);
    cout << res;
    return 0;
}