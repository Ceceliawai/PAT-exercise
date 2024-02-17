#include <iostream>
#include <string>

using namespace std;

string digits = "0123456789ABC";

int main() {
    int R, G, B;
    string r, g, b;
    cin >> R >> G >> B;
    r = "";
    r = r + digits[R % 13];
    r = digits[R / 13] + r;

    g = "";
    g = g + digits[G % 13];
    g = digits[G / 13] + g;

    b = "";
    b = b + digits[B % 13];
    b = digits[B / 13] + b;

    cout << "#";
    if (r.length() == 1) cout << "0";
    if (r.length() == 0) cout << "00";
    cout << r;
    if (g.length() == 1) cout << "0";
    if (g.length() == 0) cout << "00";
    cout << g;
    if (b.length() == 1) cout << "0";
    if (b.length() == 0) cout << "00";
    cout << b;
    return 0;
}