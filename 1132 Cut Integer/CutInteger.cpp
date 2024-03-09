#include <string.h>

#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        string a = s.substr(0, s.length() / 2);
        string b = s.substr(s.length() / 2);
        int x = stoi(a);
        int y = stoi(b);
        int z = stoi(s);
        if (x == 0 || y == 0) {
            cout << "No" << endl;
        } else {
            if (z % (x * y) == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}