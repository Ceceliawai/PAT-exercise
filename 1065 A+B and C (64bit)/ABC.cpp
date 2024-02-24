/*
    高精度加减法
*/
#include <iostream>
#include <string>
using namespace std;
bool myres[12];
string myAdd(string s1, string s2) {
    if (s2 == "0") return s1;
    if (s1 == "0") return s2;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    string res = "";
    int c = 0;
    for (; i >= 0 && j >= 0; i--, j--) {
        int a = s1[i] - '0';
        int b = s2[j] - '0';
        int k = a + b + c;
        if (k > 10) {
            c = 1;
            k = k % 10;
        } else
            c = 0;
        char op = k + '0';
        res = op + res;
    }
    while (i >= 0) {
        int a = s1[i] - '0';
        int k = a + c;
        if (k > 10) {
            c = 1;
            k = k % 10;
        } else
            c = 0;
        char op = k + '0';
        res = op + res;
        i--;
    }
    while (j >= 0) {
        int a = s2[j] - '0';
        int k = a + c;
        if (k > 10) {
            c = 1;
            k = k % 10;
        } else
            c = 0;
        char op = k + '0';
        res = op + res;
        j--;
    }
    if (c == 1) res = "1" + res;
    return res;
}
string mySub(string s1, string s2) {
    if (s2 == "0") return s1;
    if (s1 == "0") return s2;
    if (s1 == s2) return "0";
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    string res = "";
    int c = 0;
    for (; i >= 0 && j >= 0; i--, j--) {
        int a = s1[i] - '0';
        int b = s2[j] - '0';
        int k = a - b - c;
        if (k < 0) {
            c = 1;
            k = k + 10;
        } else
            c = 0;
        char op = k + '0';
        res = op + res;
        res = op + res;
    }
    while (i >= 0) {
        int a = s1[i] - '0';
        int k = a - c;
        if (k < 0) {
            c = 1;
            k = k % 10;
        } else
            c = 0;
        char op = k + '0';
        res = op + res;
        i--;
    }
    while (j >= 0) {
        int a = s2[j] - '0';
        int k = a + c;
        if (k > 10) {
            c = 1;
            k = k % 10;
        } else
            c = 0;
        char op = k + '0';
        res = op + res;
        j--;
    }
    if (c == 1) res = "-" + res;
    return res;
}
bool LargerThan(string s1, string s2) {
    if (s1[0] != '-' && s2[0] == '-') return true;
    if (s1[0] == '-' && s2[0] != '-') return false;
    if (s1[0] == '-' && s2[0] == '-') {
        string a = s1.substr(1);
        string b = s2.substr(1);
        if (a.length() > b.length())
            return false;
        else if (a.length() < b.length())
            return true;
        else
            return a < b;
    }
    if (s1[0] != '-' && s2[0] != '-') {
        string a = s1;
        string b = s2;
        if (a.length() > b.length())
            return true;
        else if (a.length() < b.length())
            return false;
        else
            return a > b;
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        string res;
        if (s1[0] == '-' && s2[0] == '-') {
            string a = s1.substr(1);
            string b = s2.substr(1);
            res = myAdd(a, b);
            res = "-" + res;

        } else if (s1[0] != '-' && s2[0] != '-') {
            res = myAdd(s1, s2);
        } else if (s1[0] != '-' && s2[0] == '-') {
            string b = s2.substr(1);
            res = mySub(s1, b);
        } else if (s1[0] == '-' && s2[0] != '-') {
            string b = s1.substr(1);
            res = mySub(s2, b);
        }
        myres[i] = LargerThan(res, s3);
    }
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << endl;
        cout << "Case #" << i + 1 << ": ";
        if (myres[i] == false)
            cout << "false";
        else
            cout << "true";
    }
}