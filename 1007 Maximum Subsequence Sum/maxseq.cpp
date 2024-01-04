#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int nums[N];
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  bool flag = false;
  int maxsum = 0;
  int maxi = 0;
  int maxj = 0;
  int i = 0;
  int j = -1;
  int sum = 0;
  for (int k = 0; k < N; k++) {
    if (nums[k] > 0) {
      if (j + 1 < N) j++;
      sum += nums[k];
      flag = true;
      if (sum > maxsum) {
        maxi = i;
        maxj = j;
        maxsum = sum;
      }
    } else {
      if (sum + nums[k] < 0) {
        i = k + 1;
        j = k;
        sum = 0;
      } else {
        if (j + 1 < N) j++;
        sum += nums[k];
      }
    }
  }
  if (flag == true) {
    cout << maxsum << ' ' << nums[maxi] << ' ' << nums[maxj];
  } else {
    cout << "0 " << nums[0] << ' ' << nums[N - 1];
  }
  return 0;
}
