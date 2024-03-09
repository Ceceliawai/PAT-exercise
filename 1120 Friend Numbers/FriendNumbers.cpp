#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> res;
int getid(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        int index = getid(num);
        res.insert(index);
    }
    cout << res.size() << endl;
    int cnt = 0;
    for (int c : res) {
        if (cnt != 0) cout << " ";
        cnt++;
        cout << c;
    }
    return 0;
}