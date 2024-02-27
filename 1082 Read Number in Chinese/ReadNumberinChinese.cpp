#include <algorithm>
#include <iostream>
using namespace std;
string nums[10] = {"ling", "yi",  "er", "san", "si",
                   "wu",   "liu", "qi", "ba",  "jiu"};
string danwei[4] = {"", " Qian", " Bai", " Shi"};
// 注意空格的输出，单位前面输出一个，剩下的一个在数字前面输出，这样可以控制第一个数不输出
int main() {
    int digits[9];
    int num;
    bool flag;
    cin >> num;
    if (num == 0) {
        cout << "ling";
        return 0;
    }
    if (num > 0)
        flag = true;
    else {
        flag = false;
        num = -num;
    }
    fill(digits, digits + 9, 0);
    int n = num;
    int i = 8;
    while (n != 0) {
        digits[i] = n % 10;
        n = n / 10;
        i--;
    }
    if (flag == false) cout << "Fu ";
    int zerc = 0;
    //
    for (int j = i + 1; j <= 8; j++) {
        // 从第一个非0的数开始
        if (digits[j] == 0)
            zerc++;
        else {
            if (zerc != 0) cout << " ling";
            if (j == i + 1)
                cout << nums[digits[j]];  // 不输出空格
            else
                cout << " " << nums[digits[j]];  // 输出空格
            zerc = 0;
            cout << danwei[j % 4];
        }
        if (j == 4) cout << " Wan";
    }
    return 0;
}