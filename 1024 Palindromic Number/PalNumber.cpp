#include <iostream>
#include <string>

using namespace std;

char digit[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool IsPar(string s) {
    if (s.length() == 1) return true;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) return false;
    }
    return true;
}

string Option(string s) {
    string rs = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        // if (s[i] == '0') continue;  // the 0 at the begin of the number
        // 我知道了，这样你所有的0都跳过了，所以才错。按理说只需要跳过最开头的
        // 但其实你不跳过开头的0也没事，因为不跳过它加上也是0嘛，这样还省得判断了
        rs = rs + s[i];
    }
    int c = 0;  // jinwei

    string res = "";
    int i;
    for (i = 0; i < s.length(); i++) {
        int a = s[s.length() - 1 - i] - '0';
        int b = rs[rs.length() - 1 - i] - '0';
        int num = a + b + c;
        if (num >= 10) {
            num = num % 10;
            c = 1;
        } else
            c = 0;
        res = digit[num] + res;
    }
    if (c == 1) res = "1" + res;
    return res;
}

int main() {
    string num;
    int maxcount;
    cin >> num >> maxcount;

    int op_counts = 0;
    while (IsPar(num) == false && op_counts < maxcount) {
        string newnum = Option(num);
        num = newnum;
        op_counts++;
    }

    cout << num << endl;
    cout << op_counts;
}