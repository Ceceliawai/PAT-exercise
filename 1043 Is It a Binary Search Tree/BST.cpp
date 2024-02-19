#include <iostream>

using namespace std;

int preorder[1000];
int postorder[1000];
int N;

bool IsBST(int root, int left, int right) {
    if (left > right) {
        if (root >= 0 && root < N) postorder[root] = preorder[root];
        return true;
    }                // 节点为空，不需要进行任何操作
    int index = -1;  // 分界点的index
    int f = 0;       // f=0小于 f=1大于
    bool flag = true;

    // 判断当前root的子树是否可能构成BST
    for (int i = left; i <= right; i++) {
        if (f == 0) {
            if (preorder[i] >= preorder[root]) {  // 右子树大于等于
                index = i;
                f = 1;  // 进入右子树范围了
            }
        } else if (f == 1) {
            if (preorder[i] < preorder[root]) {
                flag = false;
                break;
            }
        }
    }
    if (flag == false) return false;

    bool f1 = true;
    bool f2 = true;
    if (index == -1) {  // 全是左子树
        f1 = IsBST(left, left + 1, right);
    } else {
        // flag=true，需要进行一些个处理
        f1 = IsBST(left, left + 1, index - 1);
        f2 = IsBST(index, index + 1, right);
    }
    if (f1 == false || f2 == false) return false;

    // 子树也都是BST，那么就需要进行移动
    for (int i = root; i < right; i++) {
        postorder[i] = postorder[i + 1];
    }
    postorder[right] = preorder[root];
    return true;
}

bool IsRBST(int root, int left, int right) {
    if (left > right) {
        if (root >= 0 && root < N) postorder[root] = preorder[root];
        return true;
    }                // 节点为空，不需要进行任何操作
    int index = -1;  // 分界点的index
    int f = 0;       // f=0小于 f=1大于
    bool flag = true;

    // 判断当前root的子树是否可能构成BST
    for (int i = left; i <= right; i++) {
        if (f == 0) {
            if (preorder[i] <
                preorder[root]) {  // 反转后左子树大于等于，右子树纯小于
                index = i;
                f = 1;  // 进入右子树范围了
            }
        } else if (f == 1) {
            if (preorder[i] >= preorder[root]) {
                flag = false;
                break;
            }
        }
    }
    if (flag == false) return false;

    bool f1 = true;
    bool f2 = true;

    if (index == -1) {  // 全是左子树
        f1 = IsRBST(left, left + 1, right);
    } else {
        // flag=true，需要进行一些个处理
        f1 = IsRBST(left, left + 1, index - 1);
        f2 = IsRBST(index, index + 1, right);
    }

    // 子树也都是BST，那么就需要进行移动
    for (int i = root; i < right; i++) {
        postorder[i] = postorder[i + 1];
    }
    postorder[right] = preorder[root];
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> preorder[i];
    }
    if (IsBST(0, 1, N - 1) == true) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            if (i != 0) cout << " ";
            cout << postorder[i];
        }
        return 0;
    }
    if (IsRBST(0, 1, N - 1) == true) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            if (i != 0) cout << " ";
            cout << postorder[i];
        }
        return 0;
    }

    cout << "NO";
    return 0;
}
