/**
 * @file 1040 Longest Symmetric String
 * @brief 查找一个字符串中的最长回文串
 * @details
 * 双重循环，i从头开始，j从尾开始，判断当前串是否是回文串。如果大于最大值，更新。
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int max = 1;  // 最少的情况就是单个字母
    for (int i = 0; i < s.length(); i++) {
        for (int j = s.length() - 1; j >= i; j--) {
            int l = i;
            int r = j;
            if (r - l < max) continue;  // 剪枝
            while (s[l] == s[r] && l < r) {
                l++;
                r--;
            }
            // 因为l>=r退出的循环
            if (l >= r && j - i > max) max = j - i + 1;
        }
    }
    cout << max;
}
