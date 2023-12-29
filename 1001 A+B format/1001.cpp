/*
A+B format: canculate the sum of A and B, then output it
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int sum;
  sum = a + b;
  string s;
  if (sum < 0) {
    cout << '-';
    s = to_string(-sum);
  } else
    s = to_string(sum);
  const char *ch = s.c_str();
  int i = s.length();
  int index = i % 3;
  for (i = 0; i < s.length(); i++) {
    if (index % 3 == 0 && i != 0) {
      cout << ',';
      index = 3;
    }
    cout << ch[i];
    index--;
  }
}