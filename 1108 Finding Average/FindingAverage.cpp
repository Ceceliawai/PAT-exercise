#include <string.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> error;
double mysum = 0;
int cnt = 0;
bool translate(string s) {
    bool flag = true;
    bool dian = false;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-' && i != 0)
            return false;
        else if (s[i] == '-' && i == 0) {
            // 不做任何操作
        } else if ((s[i] < '0' || s[i] > '9') && s[i] != '.') {
            return false;
        } else if (s[i] == '.') {
            if (dian == true)
                return false;
            else
                dian = true;
        } else {
            if (dian == true) cnt++;
        }
    }
    if (cnt > 2) return false;
    return true;
}
int main() {
    int N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (translate(s) == true && stod(s) >= -1000 && stod(s) <= 1000) {
            mysum += stod(s);
        } else {
            error.push_back(s);
        }
    }
    for (int i = 0; i < error.size(); i++) {
        cout << "ERROR: " << error[i] << " is not a legal number" << endl;
    }
    if (N - error.size() == 0) {
        cout << "The average of 0 numbers is Undefined";
    } else if (N - error.size() == 1) {
        printf("The average of %d number is %.2f", N - error.size(),
               mysum * 1.0 / (N - error.size()));
    } else {
        printf("The average of %d numbers is %.2f", N - error.size(),
               mysum * 1.0 / (N - error.size()));
    }
    return 0;
}