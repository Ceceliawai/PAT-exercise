#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
string DAY[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int d, h, s;
    int i = 0;
    string res = "";
    for (; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')) {
            d = s1[i] - 'A';
            break;
        }
    }
    i++;
    for (; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') ||
                               (s1[i] >= '0' && s1[i] <= '9'))) {
            if (s1[i] >= '0' && s1[i] <= '9') {
                h = s1[i] - '0';
            } else {
                h = s1[i] - 'A' + 10;
            }
            break;
        }
    }
    for (i = 0; i < s3.length() && i < s4.length(); i++) {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') ||
                               (s3[i] >= 'A' && s3[i] <= 'Z'))) {
            s = i;
            break;
        }
    }
    cout << DAY[d];
    cout << " ";
    printf("%02d:%02d", h, s);
    return 0;
}