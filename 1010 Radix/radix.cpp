#include <iostream>
#include <string>
using namespace std;

int turnttoint(char op) {
  if (op >= '0' && op <= '9')
    return op - '0';
  else if (op >= 'a' && op <= 'z')
    return op - 'a' + 10;
}

int findmax(string str) {
  char op = '0';
  for (int i = 0; i < str.length(); i++) {
    if (str[i] > op) op = str[i];
  }
  return turnttoint(op);
}

int turntonum(string str, int r) {
  int sum = 0;
  for (int i = 0; i < str.length(); i++) {
    sum = sum * r + turnttoint(str[i]);
  }
  return sum;
}

int main() {
  string N1, N2;
  int tag, radix;
  cin >> N1 >> N2 >> tag >> radix;
  int num;
  if (tag == 1) {
    num = turntonum(N1, radix);
    for (int k = findmax(N2); k <= 36; k++) {
      if (turntonum(N2, k) == num) {
        cout << k;
        return 0;
      }
    }
  }
  if (tag == 2) {
    num = turntonum(N2, radix);
    for (int k = findmax(N1) + 1; k <= 36; k++) {
      if (turntonum(N1, k) == num) {
        cout << k;
        return 0;
      }
    }
  }
  cout << "Impossible";
  return 0;
}
