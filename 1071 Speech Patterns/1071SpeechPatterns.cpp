#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
int mycount[1048576], cnt = 0;
using namespace std;
vector<string> words;
map<string, int> toindex;
bool mycmp(string a, string b) {
    int x = mycount[toindex[a]];
    int y = mycount[toindex[b]];
    if (x != y)
        return x > y;
    else
        return a < b;
}
int main() {
    char op = ' ';
    string temp = "";
    while (op != '\n') {
        op = getchar();
        if (op >= '0' && op <= '9') {
            temp += op;
        } else if (op >= 'a' && op <= 'z') {
            temp += op;
        } else if (op >= 'A' && op <= 'Z') {
            op = op - 'A' + 'a';
            temp += op;
        } else {
            if (temp != "") {
                if (toindex.count(temp) == 0) {
                    toindex[temp] = cnt;
                    words.push_back(temp);
                    mycount[cnt] = 1;
                    cnt++;
                } else {
                    mycount[toindex[temp]]++;
                }
                temp = "";
            }
        }
    }
    cnt--;
    sort(words.begin(), words.end(), mycmp);
    cout << words[0] << " " << mycount[toindex[words[0]]];
    return 0;
}
