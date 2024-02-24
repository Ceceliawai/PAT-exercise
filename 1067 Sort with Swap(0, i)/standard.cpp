// 贪心策略：每一次将一个数放在它该有的位置
#include <iostream>
using namespace std;
int index[100010];
void Swap(int a, int b) {
    int t = index[a];
    index[a] = index[b];
    index[b] = t;
    return;
}
int main() {
    int N, num, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        index[num] = i;
    }
    for (int i = 0; i < N; i++) {
        int curin = index[i];
        while (index[0] != 0) {
            swap(index[0], index[index[0]]);
            // index[0]是0目前所在的位置，设为i
            // index[index[0]]=index[i]，即本来应该在这个位置的那个数
            // 持续这个交换，直到0回到本位
            // 这个操作可以保证每次都有一个数回到它的位置，后续都不需要再交换了
            cnt++;
        }
        if (index[i] != i) {
            // 还有没到自己位置的，需要和0交换，也只能和0交换
            swap(index[0], index[i]);
            cnt++;
        }
    }
    cout << cnt;
}