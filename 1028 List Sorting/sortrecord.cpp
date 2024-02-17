#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, C;

typedef struct Student {
    int ID;
    string name;
    int grade;
} stu;

bool cmp(stu s1, stu s2) {
    switch (C) {
        case 1:
            return s1.ID < s2.ID;
            break;
        case 2:
            if (s1.name != s2.name) return s1.name < s2.name;
            return s1.ID < s2.ID;
            break;
        case 3:
            if (s1.grade != s2.grade) return s1.grade < s2.grade;
            return s1.ID < s2.ID;
            break;
    }
}

int main() {
    cin >> N >> C;
    vector<stu> s;
    for (int i = 0; i < N; i++) {
        int id, grade;
        string name;
        cin >> id >> name >> grade;
        stu newstu;
        newstu.ID = id;
        newstu.name = name;
        newstu.grade = grade;
        s.push_back(newstu);
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++) {
        printf("%06d", s[i].ID);
        cout << " " << s[i].name << " " << s[i].grade << endl;
    }
    return 0;
}