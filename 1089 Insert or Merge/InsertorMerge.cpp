#include <algorithm>
#include <iostream>
using namespace std;
int origin[110], input[110];  // 原始数据，排序几趟后的数据
int N;
/**
 * @brief 在pre+1和index之间插入数key
 *
 * @param key 要插入的元素
 * @param index 要插入元素在原始序列中的位置
 * @param pre 此序列开始位置的前一个（用于实现merge sort）
 * @return ** void
 */
void insert(int key, int index, int pre) {
    if (index == 1) {
        input[index] = key;
        return;
    }
    input[0] = input[index];
    int j;
    for (j = index - 1; j > pre; j--) {
        if (input[0] < input[j])
            input[j + 1] = input[j];
        else
            break;
    }
    j = max(pre + 1, j + 1);
    input[j] = input[0];
    return;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> origin[i];
    for (int i = 1; i <= N; i++) cin >> input[i];
    int pre, cur;
    pre = 1;
    cur = 1;
    bool flag = true;  // true代表insert
    for (int i = 2; i <= N; i++) {
        if (origin[i] != input[i]) {
            // 向前判断
            // 如果有变动，但不是完全递增，说明不是insert
            cur = i;
            int val = input[cur];
            for (int j = cur - 1; j >= pre - 1 && j >= 1; j--) {
                if (input[j] > val) {
                    flag = false;
                    break;
                } else
                    val = input[j];
            }
            pre = cur;
            if (flag == false) break;
        }
    }
    if (flag == true) {
        // insert
        cout << "Insertion Sort" << endl;
        // 找到第一个未排序的数
        int i;
        for (i = 2; i <= N; i++) {
            if (input[i] < input[i - 1]) break;
        }
        // 再插入一个数
        insert(input[i], i, 0);
        for (int i = 1; i <= N; i++) {
            if (i != 1) cout << " ";
            cout << input[i];
        }
    } else {
        // merge
        cout << "Merge Sort" << endl;
        int d = 1;
        int mind = N + 1;
        // 找到当前的序列长度，是有序序列中最短的那个
        for (int i = 2; i <= N; i++) {
            if (input[i] > input[i - 1])
                d++;
            else {
                mind = min(d, mind);
                d = 1;
            }
        }
        int pre = 0;  // 上一个排序的位置
        int i;
        for (i = 1; i <= N; i = i + mind * 2) {
            pre = i - 1;
            // i到i+mind-1是已经排好序的序列1
            // i+mind到i+mind*2-1是已经排好序的序列2
            // 把i+mind到i+mind*2-1的数依次插入排序
            // 最终使得i到i+mind*2-1是有序的
            // 下一个开始位置：i+mind*2
            for (int j = i + mind; j < i + mind * 2 && j <= N; j++) {
                insert(input[j], j, pre);
            }
        }
        int j = i;
        while (j <= N) {
            insert(input[j], j, i - 1);
        }
        for (int i = 1; i <= N; i++) {
            if (i != 1) cout << " ";
            cout << input[i];
        }
    }
    return 0;
}
