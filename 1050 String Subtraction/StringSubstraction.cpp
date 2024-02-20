#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int charcount[150];
int main() {
    fill(charcount, charcount + 150, 0);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.length(); i++) {
        charcount[b[i] - '\0']++;
    }
    for (int i = 0; i < a.length(); i++) {
        if (charcount[a[i] - '\0'] == 0) cout << a[i];
    }
    return 0;
}