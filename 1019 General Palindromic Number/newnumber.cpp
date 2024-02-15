#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N, b;
  cin >> N >> b;
  int num = N;
  vector<int> a;
  a.clear();
  while (num != 0) {
    int temp = num % b;
    a.push_back(temp);
    num = num / b;
  }

  int flag = true;
  if (a.size() == 0) {
    cout << "Yes" << endl << "0" << endl;
    return 0;
  }
  if (a.size() != 1) {
    for (int i = 0; i < a.size() / 2; i++) {
      if (a[i] != a[a.size() - 1 - i]) {
        flag = false;
        break;
      }
    }
  }
  if (flag == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  for (int i = a.size() - 1; i >= 0; i--) {
    cout << a[i];
    if (i != 0) cout << " ";
  }
  cout << endl;
}