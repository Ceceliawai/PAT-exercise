// 找到所有字符串相同的后缀？
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string temp = "";
    int N;
    cin >> N;
    vector<string> lines;
    int minl = (0x1) << 30;
    getchar();  // getline之前有cin一个int的情况需要getchar吸收回车
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);  // 一行内可能有空格，所以用getline
        lines.push_back(s);
        minl = s.length() < minl ? s.length() : minl;
    }
    for (int i = 0; i < minl; i++) {
        char op = lines[0][lines[0].length() - i - 1];
        bool flag = true;
        for (int j = 1; j < lines.size(); j++) {
            if (lines[j][lines[j].length() - i - 1] != op) {
                flag = false;
                break;
            }
        }
        if (flag == false)
            break;
        else
            temp = op + temp;
    }
    if (temp == "") {
        cout << "nai";
    } else
        cout << temp;
    return 0;
}
