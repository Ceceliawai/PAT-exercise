#include <iostream>
#include <string>
#include <vector>
using namespace std;
string myoutput(string s, int N) {
    vector<int> n;
    int c = 0;
    bool flag = false;
    string r = "";
    int i = 0;
    while (s[i] == '0') i++;
    if (s[i] != '.') {
        for (; i < s.length(); i++) {
            if (s[i] != '.') {
                n.push_back(s[i] - '0');
            } else
                flag = true;
            if (flag == false) c++;
        }
        while (n.size() < N) {
            n.push_back(0);
        }
        r = "0.";
        for (int i = 0; i < N; i++) {
            r += (n[i] + '0');
        }
        r += "*10^";
        r += to_string(c);
    } else {
        bool initial = true;
        i++;
        for (; i < s.length(); i++) {
            char cp = s[i];
            if (cp != '0') initial = false;
            if (initial == true && cp == '0') {
                c++;
                continue;
            }
            n.push_back(cp - '0');
        }
        while (n.size() < N) {
            n.push_back(0);
        }
        if (initial == true) {
            // 全是0
            r = "0.";
            c = 0;
            while (c < N) {
                r += '0';
                c++;
            }
            r += "*10^0";
        } else {
            r = "0.";
            for (int i = 0; i < N; i++) {
                r += (n[i] + '0');
            }
            if (c != 0)
                r += "*10^-";
            else
                r += "*10^";
            r += to_string(c);
        }
    }
    return r;
}
int main() {
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;
    string r1 = myoutput(s1, N);
    string r2 = myoutput(s2, N);
    if (r1 == r2) {
        cout << "YES " << r1;
    } else {
        cout << "NO " << r1 << " " << r2;
    }
    return 0;
}