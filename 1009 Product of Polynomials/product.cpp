#include <stdio.h>

#include <iostream>
using namespace std;

int main() {
  int K1, K2;
  // deal with the input
  int maxe = 0;
  cin >> K1;
  double A1[K1];
  int E1[K1];
  for (int i = 0; i < K1; i++) {
    cin >> E1[i];
    cin >> A1[i];
    if (E1[i] > maxe) maxe = E1[i];
  }
  cin >> K2;
  double A2[K2];
  int E2[K2];
  for (int i = 0; i < K2; i++) {
    cin >> E2[i];
    cin >> A2[i];
    if (E2[i] > maxe) maxe = E2[i];
  }

  double A[maxe * 2 + 1];
  for (int i = 0; i < maxe * 2 + 1; i++) {
    A[i] = 0;
  }
  for (int i = 0; i < K1; i++) {
    for (int j = 0; j < K2; j++) {
      int e = E1[i] + E2[j];
      double c = A1[i] * A2[j];
      A[e] += c;
    }
  }

  int count = 0;
  for (int i = 0; i < maxe * 2 + 1; i++) {
    if (A[i] != 0.0) count++;
  }
  cout << count;
  for (int i = maxe * 2; i >= 0; i--) {
    if (A[i] != 0.0) {
      cout << ' ';
      cout << i;
      cout << ' ';
      printf("%.1f", A[i]);
    }
  }
  return 0;
}
