#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.length();
    int n1, n2, k;
    for (int i = 3; i <= N; i++) {
        k = (N + 2 - i) / 2;
        if ((N + 2 - i) % 2 != 0)
            continue;
        else {
            if (k <= i) {
                n1 = k;
                n2 = i;
                break;
            }
        }
    }

    for (int i = 0; i < n1 - 1; i++) {
        cout << s[i];
        for (int j = 0; j < n2 - 2; j++) cout << " ";
        cout << s[s.length() - 1 - i];
        cout << endl;
    }
    for (int i = n1 - 1; i < n1 + n2 - 1; i++) {
        cout << s[i];
    }
    return 0;
}
