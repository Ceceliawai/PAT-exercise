#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Student {
    string ID;
    int location_num;
    int score;
    int local_rank;
    int total_rank;
} stu;

int N;

bool cmp_local(stu s1, stu s2) {
    if (s1.location_num != s2.location_num)
        return s1.location_num < s2.location_num;

    if (s1.score != s2.score) return s1.score > s2.score;
    return s1.ID < s2.ID;
}

bool cmp_total(stu s1, stu s2) {
    if (s1.score != s2.score) return s1.score > s2.score;
    return s1.ID < s2.ID;
}

int main() {
    cin >> N;

    vector<stu> allstu;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            string id;
            int score;
            cin >> id >> score;
            stu newstu;
            newstu.ID = id;
            newstu.score = score;
            newstu.location_num = i + 1;
            allstu.push_back(newstu);
        }
    }

    sort(allstu.begin(), allstu.end(), cmp_local);
    int rank = 1;
    int count = 0;
    int now_score = -1;
    for (int i = 0; i < allstu.size(); i++) {
        if (allstu[i].score > now_score) {
            // new location
            rank = 1;
            now_score = allstu[i].score;
            count = 1;
            allstu[i].local_rank = rank;
        } else if (allstu[i].score == now_score) {
            // rank不变
            count++;
            allstu[i].local_rank = rank;
        } else {
            rank += count;
            count = 1;
            now_score = allstu[i].score;
            allstu[i].local_rank = rank;
        }
    }

    sort(allstu.begin(), allstu.end(), cmp_total);
    rank = 1;
    now_score = -1;
    count = 1;
    for (int i = 0; i < allstu.size(); i++) {
        if (allstu[i].score > now_score) {
            // new location
            rank = 1;
            count = 1;
            now_score = allstu[i].score;
            allstu[i].total_rank = rank;
        } else if (allstu[i].score == now_score) {
            // rank不变
            count++;
            allstu[i].total_rank = rank;
        } else {
            rank += count;
            count = 1;
            now_score = allstu[i].score;
            allstu[i].total_rank = rank;
        }
    }

    cout << allstu.size() << endl;
    for (int i = 0; i < allstu.size(); i++) {
        if (i != 0) cout << endl;
        cout << allstu[i].ID;
        cout << ' ';
        cout << allstu[i].total_rank;
        cout << ' ';
        cout << allstu[i].location_num;
        cout << ' ';
        cout << allstu[i].local_rank;
    }

    return 0;
}
