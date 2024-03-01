#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int ac[130], bc[130];
int getid(char op) {
    if (op >= '0' && op <= '9') return op - '0';
    if (op >= 'a' && op <= 'z') return op - 'a' + 10;
    if (op >= 'A' && op <= 'Z') return op - 'A' + 36;
    return -1;
}
int main() {
    string a, b;
    fill(ac, ac + 130, 0);
    fill(bc, bc + 130, 0);
    cin >> a >> b;
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        ac[getid(a[i])]++;
    }
    for (int i = 0; i < b.length(); i++) {
        bc[getid(b[i])]++;
    }
    for (int i = 0; i < 62; i++) {
        if (ac[i] < bc[i]) {
            flag = false;
            cnt += bc[i] - ac[i];
        }
    }
    if (flag == true) {
        cout << "Yes " << a.length() - b.length();
    } else {
        cout << "No " << cnt;
    }
    return 0;
}