// 骞虫柟鎺㈡祴娉? +1 -1 +4 -4 +9 -9
#include <algorithm>
#include <iostream>
using namespace std;
int HashTable[10010];
int nums[10010];
int nindex[10010];
bool IsPrime(int num) {
    if (num == 1) return false;
    if (num == 2) return true;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main() {
    int N, MSize;
    cin >> MSize >> N;
    while (IsPrime(MSize) == false) MSize++;
    fill(HashTable, HashTable + 10010, -1);
    fill(nindex, nindex + 10010, -1);
    for (int i = 0; i < N; i++) {
        int index, h;
        cin >> nums[i];
        for (int j = 0; j <= MSize / 2; j++) {
            index = (nums[i] + j * j) % MSize;
            if (HashTable[index] == -1) {
                HashTable[index] = nums[i];
                nindex[i] = index % MSize;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        if (nindex[i] != -1)
            cout << nindex[i];
        else
            cout << "-";
    }
    return 0;
}