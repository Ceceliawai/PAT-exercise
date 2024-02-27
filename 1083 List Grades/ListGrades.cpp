#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 没给N的范围，可以开一个大一点的数组，但最好是直接用vector
typedef struct student {
    char name[11];
    char id[11];
    int grade;
} stu;
vector<stu> allstu;
vector<stu> ranklist;
int N, grade1, grade2;
bool mycmp(stu s1, stu s2) { return s1.grade > s2.grade; }
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        stu news;
        cin >> news.name;
        cin >> news.id;
        cin >> news.grade;
        allstu.push_back(news);
    }
    cin >> grade1 >> grade2;
    grade1 = max(0, grade1);
    grade2 = min(grade2, 100);
    for (int i = 0; i < N; i++) {
        if (allstu[i].grade <= grade2 && allstu[i].grade >= grade1) {
            ranklist.push_back(allstu[i]);
        }
    }
    sort(ranklist.begin(), ranklist.end(), mycmp);
    if (ranklist.size() == 0) {
        cout << "NONE";
    } else {
        for (int i = 0; i < ranklist.size(); i++) {
            cout << ranklist[i].name;
            cout << " ";
            cout << ranklist[i].id;
            cout << endl;
        }
    }
    return 0;
}