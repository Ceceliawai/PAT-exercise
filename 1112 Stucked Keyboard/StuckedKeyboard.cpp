#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> keys;
int getid(char op) {
    if (op >= 'a' && op <= 'z')
        return op - 'a';
    else if (op >= '0' && op <= '9')
        return op - '0' + 26;
    else
        return 36;
}
int main() {
    string s;
    int k;
    cin >> k;
    cin >> s;

    bool error[37];
    fill(error, error + 37, true);
    char op = '\0';
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == op) {
            cnt++;
        } else {
            if (cnt < k && op != '\0') {
                error[getid(op)] = false;
            }
            op = s[i];
            cnt = 1;
        }
        if (cnt >= k && count(keys.begin(), keys.end(), op) == 0) {
            keys.push_back(op);
        }
    }
    if (cnt < k && op != '\0') {
        error[getid(op)] = false;
    }
    for (int i = 0; i < keys.size(); i++) {
        if (error[getid(keys[i])] == true) cout << keys[i];
    }
    cout << endl;

    op = '\0';
    cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == op) {
            cnt++;
        } else {
            if (op != '\0' && error[getid(op)] == false)
                for (int j = 0; j < cnt; j++) {
                    cout << op;
                }
            else {
                for (int j = 0; j < cnt / k; j++) {
                    cout << op;
                }
            }
            op = s[i];
            cnt = 1;
        }
    }

    if (op != '\0' && error[getid(op)] == false)
        for (int j = 0; j < cnt; j++) {
            cout << op;
        }
    else {
        for (int j = 0; j < cnt / k; j++) {
            cout << op;
        }
    }
    return 0;
}
