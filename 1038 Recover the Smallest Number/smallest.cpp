#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 从小到大的顺序排序
bool mycmp(string s1, string s2) {
    int i;
    for (i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] < s2[i])
            return true;
        else if (s1[i] > s2[i])
            return false;
    }
    // 到一个串结束为止都一样
    if (i == s1.size()) {
        // // s2剩下
        // if (s2[i] < s2[0])
        //     return false;  // s2排在前面
        // else
        //     return true;
        for (int j = 0; j + i < s2.size(); j++) {
            if (s2[i + j] < s2[j])
                return false;  // s2排在前面
            else if (s2[i + j] > s2[j])
                return true;
        }
    } else if (i == s2.size()) {
        for (int j = 0; j + i < s1.size(); j++) {
            if (s1[i + j] < s1[j])
                return true;
            else if (s1[i + j] > s1[j])
                return false;
        }
    }
    return true;
}

bool cmp(string s1, string s2) {
    string a = s1 + s2;
    string b = s2 + s1;
    return a < b;
}

vector<string> v;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), mycmp);
    string res = "";
    for (int i = 0; i < v.size(); i++) {
        res += v[i];
    }

    bool flag = true;
    for (int i = 0; i < res.size(); i++) {
        if (flag == true && res[i] == '0')
            continue;
        else {
            cout << res[i];
            flag = false;
        }
    }

    if (flag == true) cout << "0";
    return 0;
}
