#include <iostream>
#include <string>
using namespace std;
bool isPalindromic(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}
string Reverse(string str) {
    string res = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        res += str[i];
    }
    return res;
}
string myAdd(string a, string b) {
    int i = 0;
    int c = 0;
    string res = "";
    for (i = 0; i < a.length() && i < b.length(); i++) {
        int digit =
            a[a.length() - 1 - i] - '0' + b[b.length() - 1 - i] - '0' + c;
        if (digit >= 10) {
            digit = digit % 10;
            c = 1;
            char op = digit + '0';
            res = op + res;
        } else {
            char op = digit + '0';
            res = op + res;
            c = 0;
        }
    }
    while (i < a.length()) {
        int digit = a[a.length() - 1 - i] + c - '0';
        if (digit >= 10) {
            digit = digit % 10;
            c = 1;
            char op = digit + '0';
            res = op + res;
        } else {
            char op = digit + '0';
            res = op + res;
            c = 0;
        }
        i++;
    }
    while (i < b.length()) {
        int digit = b[b.length() - 1 - i] + c - '0';
        if (digit >= 10) {
            digit = digit % 10;
            c = 1;
            char op = digit + '0';
            res = op + res;
        } else {
            char op = digit + '0';
            res = op + res;
            c = 0;
        }
        i++;
    }
    if (c == 1) res = "1" + res;
    return res;
}
int main() {
    string num;
    cin >> num;
    int rcount = 1;
    while (isPalindromic(num) == false && rcount <= 10) {
        string b = Reverse(num);
        cout << num << " + " << b << " = ";
        num = myAdd(num, b);
        cout << num << endl;
        rcount++;
    }
    if (rcount > 10 && isPalindromic(num) == false) {
        cout << "Not found in 10 iterations." << endl;
    } else {
        cout << num << " is a palindromic number." << endl;
    }
}