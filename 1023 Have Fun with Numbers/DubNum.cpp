#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int scount[10];
int dcount[10];

int main() {
    string s;
    cin >> s;
    fill(scount, scount + 10, 0);
    for (int i = 0; i < s.length(); i++) {
        scount[s[i] - '0']++;
    }

    // double
    string d = "";
    int c = 0;  // jin wei
    for (int i = s.length() - 1; i >= 0; i--) {
        int num = (s[i] - '0') * 2 + c;
        if (num >= 10) {
            num = num % 10;
            c = 1;
        } else
            c = 0;
        d = digits[num] + d;  // and to the high digit
    }
    if (c == 1) d = "1" + d;
    fill(dcount, dcount + 10, 0);
    for (int i = 0; i < d.length(); i++) {
        dcount[d[i] - '0']++;
    }
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        if (scount[i] != dcount[i]) {
            flag = false;
            break;
        }
    }

    if (flag == true) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;
    cout << d;
    return 0;
}
