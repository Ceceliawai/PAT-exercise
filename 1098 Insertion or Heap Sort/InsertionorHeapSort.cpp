#include <algorithm>
#include <iostream>
using namespace std;
int origin[110], input[110], N;
void buildheap() {
    int child;
    for (int i = N / 2; i >= 1; i--) {
        int k = i;  // root
        origin[0] = origin[i];
        while (k <= N) {
            int child;
            if (k * 2 > N)
                break;
            else if (k * 2 + 1 > N)
                child = k * 2;
            else
                child = origin[k * 2] > origin[k * 2 + 1] ? k * 2 : k * 2 + 1;
            if (origin[child] < origin[0])
                break;
            else {
                origin[k] = origin[child];
                k = child;
            }
        }
        origin[k] = origin[0];
    }
    return;
}
void adjust(int root, int hsize) {
    int child;
    int k = root;
    origin[0] = origin[k];
    while (k <= hsize) {
        int child;
        if (k * 2 > hsize)  // 没有孩子了
            break;
        else if (k * 2 + 1 > hsize)  // 只有左孩子了
            child = k * 2;
        else
            child = origin[k * 2] > origin[k * 2 + 1] ? k * 2 : k * 2 + 1;
        if (origin[child] <
            origin[0])  // 孩子比当前待填的数小，那就放在这个位置
            break;
        else {
            origin[k] = origin[child];  // 孩子比待填的数大，孩子上移
            k = child;
        }
    }
    origin[k] = origin[0];  // 填到合适的位置
}
bool isEqual() {
    for (int i = 1; i <= N; i++) {
        if (origin[i] != input[i]) return false;
    }
    return true;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> origin[i];
    for (int i = 1; i <= N; i++) cin >> input[i];

    // 开始检查，insert是前面一定有序
    int pre = 1;
    bool flag = true;
    for (int i = 1; i <= N; i++) {
        if (origin[i] != input[i]) {
            // 向前检查
            int val = input[i];
            for (int j = i - 1; j >= pre; j--) {
                if (val < input[j]) {
                    flag = false;
                    break;
                }
                val = input[j];
            }
            pre = i;
        }
        if (flag == false) break;
    }
    if (flag == true) {
        // insert sort
        int val = input[1];
        int i;
        for (i = 2; i <= N; i++) {
            if (input[i] < val) break;
            val = input[i];
        }
        input[0] = input[i];
        i--;
        for (; i >= 1; i--) {
            if (input[i] > input[0]) {
                input[i + 1] = input[i];
            } else
                break;
        }
        input[i + 1] = input[0];
        cout << "Insertion Sort" << endl;
        for (int i = 1; i <= N; i++) {
            if (i != 1) cout << " ";
            cout << input[i];
        }
    } else {
        // heap sort
        // 从原始序列开始：初始建堆
        // 堆顶元素和堆底互换，调整堆
        buildheap();
        int hpsize = N;
        while (isEqual() == false) {  // 依次调整，比较是否是当前趟数
            swap(origin[1], origin[hpsize]);
            adjust(1, hpsize - 1);
            hpsize--;
        }
        // 再heap sort一次
        swap(origin[1], origin[hpsize]);
        adjust(1, hpsize - 1);
        cout << "Heap Sort" << endl;
        for (int i = 1; i <= N; i++) {
            if (i != 1) cout << " ";
            cout << origin[i];
        }
    }
    return 0;
}