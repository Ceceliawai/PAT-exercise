#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, K;

typedef struct Course {
    int index;
    vector<string> stu;
} course;

vector<course> c;
map<string, vector<course>> students;

bool cmp(course c1, course c2) { return c1.index < c2.index; }

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        course newc;
        newc.index = a;
        for (int j = 0; j < b; j++) {
            string s;
            cin >> s;
            newc.stu.push_back(s);
        }
        c.push_back(newc);
    }

    sort(c.begin(), c.end(), cmp);
    vector<string> need;
    for (int i = 0; i < N; i++) {
        string na;
        cin >> na;
        need.push_back(na);
    }

    for (int i = 0; i < N; i++) {
        int ccount = 0;
        vector<int> res;
        for (int j = 0; j < c.size(); j++) {
            if (count(c[j].stu.begin(), c[j].stu.end(), need[i]) != 0) {
                ccount++;
                res.push_back(c[j].index);
            }
        }
        cout << need[i];
        cout << " ";
        cout << ccount;
        for (int j = 0; j < res.size(); j++) {
            cout << " ";
            cout << res[j];
        }
        cout << endl;
    }
    return 0;
}