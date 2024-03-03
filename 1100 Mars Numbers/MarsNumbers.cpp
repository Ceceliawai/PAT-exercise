#include <string.h>

#include <iostream>
#include <string>
using namespace std;
string lows[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                   "jly",  "aug", "sep", "oct", "nov", "dec"};
string highs[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                    "hei",  "elo", "syy", "lok", "mer", "jou"};
int N;
int main() {
    cin >> N;
    getchar();
    string s;
    int num;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9') {
            num = std::stoi(s);
            int low = num % 13;
            int high = num / 13;
            if (high != 0) cout << highs[high];
            if (high != 0 && low != 0) cout << " ";
            if (low != 0) cout << lows[low];
            if (high == 0 && low == 0) cout << lows[low];
            cout << endl;
        } else {
            string high = "";
            string low = "";
            bool flag = false;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ')
                    flag = true;
                else {
                    if (flag == false)
                        high += s[i];
                    else
                        low += s[i];
                }
            }
            if (flag == false) {
                bool find = false;
                for (int i = 0; i < 13; i++) {
                    if (high == lows[i]) {
                        cout << i << endl;
                        find = true;
                        break;
                    }
                }
                if (find == false) {
                    for (int i = 0; i < 13; i++) {
                        if (high == highs[i]) {
                            cout << i * 13 << endl;
                            find = true;
                            break;
                        }
                    }
                }
            } else {
                for (int i = 0; i < 13; i++) {
                    if (high == highs[i]) {
                        num = i;
                        break;
                    }
                }
                for (int i = 0; i < 13; i++) {
                    if (low == lows[i]) {
                        num = num * 13 + i;
                        break;
                    }
                }
                cout << num << endl;
            }
        }
    }
    return 0;
}