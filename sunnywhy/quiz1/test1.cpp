#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int digits[10];
int main() {
    fill(digits, digits + 10, 0);
    string num;
    cin >> num;
    bool flag = false;
    for (int i = 0; i < num.length(); i++) {
        digits[num[i] - '0']++;
        if (num[i] != '0') flag = true;
    }
    bool res = false;
    if (digits[2] >= 1 && digits[5] >= 1) res = true;
    if (digits[0] >= 2 && flag == true) res = true;
    if (digits[7] >= 1 && digits[5] >= 1) res = true;
    if (digits[5] >= 1 && digits[0] >= 1) res = true;
    if (res == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}