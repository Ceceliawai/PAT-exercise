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
  bool flag2 = false;
  int maxsum = 0;
  int maxi = 0;
  int maxj = 0;
  int i = 0;  // start
  int j = 0;  // end
  int sum = -1;
  for (int k = 0; k < N; k++) {
    if (nums[k] >= 0) flag = true;
    if (nums[k] > 0) flag2 = true;
    if (sum < 0) {
      sum = nums[k];
      i = k;
      j = k;
    } else {
      sum += nums[k];
      j++;
    }
    if (sum > maxsum) {
      maxi = i;
      maxj = j;
      maxsum = sum;
    }
  }
  if (flag == true && flag2 == true) {
    cout << maxsum << ' ' << nums[maxi] << ' ' << nums[maxj];
  } else if (flag2 == false) {
    cout << "0 0 0";
  } else {
    cout << "0 " << nums[0] << ' ' << nums[N - 1];
  }
  return 0;
}
