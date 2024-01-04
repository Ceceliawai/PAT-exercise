#include <stdio.h>

#include <iostream>
using namespace std;

int main() {
  double c[1001];
  for (int i = 0; i < 1001; i++) {
    c[i] = 0;
  }
  double res[2001];
  for (int i = 0; i < 2001; i++) {
    res[i] = 0;
  }

  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    int e;
    double a;
    cin >> e >> a;
    c[e] = a;
  }

  cin >> K;
  for (int i = 0; i < K; i++) {
    int e;
    double a;
    cin >> e >> a;
    for (int j = 0; j < 1001; j++) {
      res[j + e] += a * c[j];
    }
  }

  int count = 0;
  for (int i = 2000; i >= 0; i--) {
    if (res[i] != 0.0) count++;
  }
  cout << count;
  for (int i = 2000; i >= 0; i--) {
    if (res[i] != 0.0) {
      cout << " ";
      cout << i;
      cout << " ";
      printf("%.1f", res[i]);
    }
  }
  return 0;
}
