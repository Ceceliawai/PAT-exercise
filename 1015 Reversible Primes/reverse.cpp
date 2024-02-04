#include <iostream>

using namespace std;

// 判断一个数是否是质数
bool isPrim(int num) {
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

// 把一个十进制的数转换成reverse之后的十进制数
int Reverse(int num, int radix) {
  if (radix == 0) return -1;
  int res = num % radix;
  int n = num / radix;
  while (n != 0) {
    res = res * radix + n % radix;
    n = n / radix;
  }
  return res;
}

int main() {
  int N, radix;
  cin >> N;
  while (N >= 0) {
    cin >> radix;
    if (isPrim(N) == false) {
      cout << "No" << endl;
    } else {
      int rN = Reverse(N, radix);
      if (isPrim(rN) == false) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
    cin >> N;
  }
  return 0;
}