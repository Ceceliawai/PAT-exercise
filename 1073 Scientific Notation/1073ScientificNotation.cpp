#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;
int main() {
    string num;
    cin >> num;
    int e;
    char s1, s2;
    vector<int> digits;
    string temp = "";
    bool E = false;  // 是否遇到了E
    s1 = num[0];
    digits.push_back(num[1] - '0');
    for (int i = 3; i < num.length(); i++) {
        if (E == false) {
            if (num[i] != 'E')
                digits.push_back(num[i] - '0');
            else {
                E = true;
                s2 = num[i + 1];
                i++;
            }
        } else {
            temp += num[i];
        }
    }
    if (s1 == '-') cout << s1;
    e = stoi(temp);
    if (s2 == '+' && e != 0) {
        int i;
        for (i = 0; i <= e; i++) {
            if (i < digits.size()) {
                cout << digits[i];
            } else
                cout << "0";
        }
        if (i < digits.size()) {
            cout << ".";
        }
        while (i < digits.size()) cout << digits[i++];
    } else if (s2 == '-' && e != 0) {
        cout << "0.";
        int i = 0;
        for (int i = 1; i < e; i++) {
            cout << "0";
        }
        for (int i = 0; i < digits.size(); i++) {
            cout << digits[i];
        }
    } else {
        cout << digits[0];
        cout << ".";
        for (int i = 1; i < digits.size(); i++) cout << digits[i];
    }
    return 0;
}