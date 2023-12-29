#define MAXN 1001
#include <stdio.h>

#include <iomanip>
#include <iostream>
using namespace std;

double sum[MAXN] = {0};

int main() {
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {
    int index;
    double c;
    cin >> index;
    cin >> c;
    sum[index] += c;
  }

  cin >> count;
  for (int i = 0; i < count; i++) {
    int index;
    double c;
    cin >> index;
    cin >> c;
    sum[index] += c;
  }

  count = 0;
  for (int i = MAXN - 1; i >= 0; i--) {
    if (sum[i] != 0) count++;
  }
  cout << count;
  for (int i = MAXN - 1; i >= 0; i--) {
    if (sum[i] != 0) {
      cout << ' ';
      cout << i;
      cout << ' ';
      // cout << setprecision(1) << sum[i];
      printf("%.1f", sum[i]);
    }
  }
}