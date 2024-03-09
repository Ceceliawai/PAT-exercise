#include <stdio.h>

#include <iostream>
using namespace std;
int point[100000], mydata[100000];
int main() {
    int root;
    int N, K;
    cin >> root >> N >> K;
    int root1 = -1;  // 负数的链表头
    int tail1 = -1;
    int root2 = -1;  // greater than K的链表头
    int tail2 = -1;
    int root3 = -1;  // 0到K的链表头
    int tail3 = -1;
    for (int i = 0; i < N; i++) {
        int add, num, next;
        cin >> add >> num >> next;
        point[add] = next;
        mydata[add] = num;
    }
    int p = root;
    while (p != -1) {
        int next = point[p];
        if (mydata[p] < 0) {
            if (root1 == -1) {
                root1 = p;
                tail1 = root1;
                point[p] = -1;
            } else {
                point[tail1] = p;
                point[p] = -1;
                tail1 = p;
            }
        } else if (mydata[p] >= 0 && mydata[p] <= K) {
            if (root2 == -1) {
                root2 = p;
                tail2 = root2;
                point[p] = -1;
            } else {
                point[tail2] = p;
                point[p] = -1;
                tail2 = p;
            }
        } else {
            if (root3 == -1) {
                root3 = p;
                tail3 = root3;
                point[p] = -1;
            } else {
                point[tail3] = p;
                point[p] = -1;
                tail3 = p;
            }
        }
        p = next;
    }
    // 连接三个结点
    if (root1 != -1) {
        root = root1;
        if (root2 != -1) {
            point[tail1] = root2;
            point[tail2] = root3;
        } else {
            point[tail1] = root3;
        }
    } else {
        if (root2 != -1) {
            // 有root2
            root = root2;
            point[tail2] = root3;
        } else {
            // 只有root3
            root = root3;
        }
    }
    p = root;
    while (p != -1) {
        int next = point[p];
        if (next == -1) {
            printf("%05d %d -1\n", p, mydata[p]);
        } else {
            printf("%05d %d %05d\n", p, mydata[p], next);
        }
        p = next;
    }
}