#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int cur = 0;
  int total = 0;
  for (int i = 0; i < N; i++) {
    int tar;
    cin >> tar;
    if (tar - cur > 0) {
      total += (tar - cur) * 6 + 5;  // up
    } else if (tar - cur < 0) {
      total += (cur - tar) * 4 + 5;  // down
    } else {
      total += 5;  // not move;
    }
    cur = tar;
  }
  cout << total;
  return 0;
}