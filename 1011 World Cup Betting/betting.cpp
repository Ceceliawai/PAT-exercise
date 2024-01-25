#include <stdio.h>

#include <iostream>
using namespace std;

int choice[3];
int scale[3];
int main() {
  float cur = 1.0;
  for (int i = 0; i < 3; i++) {
    cur = 1.0;
    for (int j = 0; j < 3; j++) {
      float tmp;
      cin >> tmp;
      if (tmp > cur) {
        cur = tmp;
        scale[i] = cur;
        choice[i] = j;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    if (choice[i] == 0) cout << "W ";
    if (choice[i] == 1) cout << "T ";
    if (choice[i] == 2) cout << "L ";
  }
  float res = (scale[0] * scale[1] * scale[2] * 0.65 - 1) * 2;
  printf("%.2f", res);
  return 0;
}