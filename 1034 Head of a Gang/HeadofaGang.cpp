#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int w[2000][2000];          // i和j之间的通话时间长度
int w_per[2000];            // 单个人的通话长度时间积累
map<string, int> names;     // 为了快速找到名字对应的下标
map<int, string> intoname;  // 找到下标对应的名字
int gang_num[2000];         // index下标的人属于哪个gang
int gang_member[2000];      // index对应的gang的人数
int gang_count = 0;         // 目前总的gang的个数
vector<string> result;      // 首领名字+人数
int cnt = 0;                // 人的个数，用于维护下标

int N, K;

int main() {
    cin >> N >> K;
    fill(w[0], w[0] + 1000 * 1000, 0);  // initial
    fill(gang_num, gang_num + 1000, -1);
    fill(w_per, w_per + 1000, 0);

    for (int i = 0; i < N; i++) {
        string a, b;
        int k;
        cin >> a >> b >> k;
        if (names.count(a) == 0) {
            names.insert(make_pair(a, cnt));
            intoname.insert(make_pair(cnt, a));
            cnt++;
        }
        if (names.count(b) == 0) {
            names.insert(make_pair(b, cnt));
            intoname.insert(make_pair(cnt, b));
            cnt++;
        }
        int ai = names[a];
        int bi = names[b];
        w[ai][bi] += k;
        w[bi][ai] += k;
        w_per[ai] += k;
        w_per[bi] += k;

        if (gang_num[ai] == -1 && gang_num[bi] == -1) {
            // 分配一个新的gang
            gang_num[ai] = gang_count;
            gang_num[bi] = gang_count;
            gang_count++;
        } else if (gang_num[ai] != -1 && gang_num[bi] == -1) {
            // 分配到跟它相关的gang里面
            gang_num[bi] = gang_num[ai];
        } else if (gang_num[ai] == -1 && gang_num[bi] != -1) {
            gang_num[ai] = gang_num[bi];
        }
    }

    for (int i = 0; i < gang_count; i++) {
        int number = 0;     // member number
        int total_val = 0;  // 通话总数
        int max = 0;        // 最长的通话时长
        int index = 0;      // 目前的head的下标
        for (int j = 0; j < cnt; j++) {
            if (gang_num[j] == i) {
                number++;
                total_val += w_per[j];
                if (w_per[j] > max) {
                    max = w_per[j];
                    index = j;
                }
            }
        }
        gang_member[i] = number;
        if (total_val / 2 > K && number > 2) {
            string a = intoname[index];
            result.push_back(a);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        cout << " ";
        cout << gang_member[gang_num[names[result[i]]]];
        cout << endl;
    }

    return 0;
}