#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct Student {
    string name;
    int h;
} stu;
vector<stu> stulist;
stu res[11][10010];
vector<int> num;
int N, K;
bool mycmp(stu s1, stu s2) {
    if (s1.h != s2.h) return s1.h < s2.h;
    return s1.name > s2.name;
}
int round() {
    double a = N * 1.0 / K;
    return (int)(a + 0.5);
}
int main() {
    cin >> N >> K;
    int rown = round();
    for (int i = 0; i < N; i++) {
        string n;
        int h;
        cin >> n >> h;
        stu news;
        news.name = n;
        h = min(300, h);
        h = max(30, h);
        news.h = h;
        stulist.push_back(news);
    }
    sort(stulist.begin(), stulist.end(), mycmp);
    int cnt = 0;
    int rnt = 0;
    while (N - cnt - rown >= rown) {
        // 剩余的还够一排
        int m = rown / 2 + 1;
        int high = cnt + rown - 1;
        int nowrnt = 1;
        res[rnt][m] = stulist[high];
        for (int i = 1; i < m; i++) {
            if (nowrnt >= rown) break;
            res[rnt][m - i] = stulist[high - nowrnt];
            nowrnt++;
            if (nowrnt >= rown) break;
            res[rnt][m + i] = stulist[high - nowrnt];
            nowrnt++;
        }
        rnt++;
        cnt += rown;
        num.push_back(rown);
    }
    if (cnt != N) {
        // 最后一排
        int m = (N - cnt) / 2 + 1;
        int high = N - 1;
        int nowrnt = 1;
        res[rnt][m] = stulist[high];
        for (int i = 1; i < m; i++) {
            if (nowrnt >= N - cnt) break;
            res[rnt][m - i] = stulist[high - nowrnt];
            nowrnt++;
            if (nowrnt >= N - cnt) break;
            res[rnt][m + i] = stulist[high - nowrnt];
            nowrnt++;
        }
        num.push_back(N - cnt);
    }
    for (int i = rnt; i >= 0; i--) {
        int rsize = num[i];
        for (int j = 1; j <= rsize; j++) {
            if (j != 1) cout << " ";
            cout << res[i][j].name;
        }
        cout << endl;
    }
    return 0;
}