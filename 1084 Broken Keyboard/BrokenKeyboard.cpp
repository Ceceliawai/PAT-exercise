#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a, b;
    cin >> a;
    cin >> b;
    string temp = "";
    int i = 0;
    int j = 0;
    vector<char> res;
    while (i < a.length() && j < b.length()) {
        char op1 = a[i];
        char op2 = b[j];
        if (op1 != op2) {
            if (op1 >= 'a' && op1 <= 'z') op1 = op1 - 'a' + 'A';
            if (count(res.begin(), res.end(), op1) == 0) res.push_back(op1);
            i++;
        } else {
            i++;
            j++;
        }
    }
    while (i < a.length()) {
        char op1 = a[i];
        if (op1 >= 'a' && op1 <= 'z') op1 = op1 - 'a' + 'A';
        if (count(res.begin(), res.end(), op1) == 0) res.push_back(op1);
        i++;
    }
    for (int i = 0; i < res.size(); i++) cout << res[i];
    return 0;
}