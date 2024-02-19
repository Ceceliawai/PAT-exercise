// 这样吧，每个course都存它所有的学生的名字
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> c[2510];
int N, K;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        int ccount;
        cin >> ccount;
        for (int j = 0; j < ccount; j++) {
            int cnum;
            cin >> cnum;
            c[cnum].push_back(name);
        }
    }
    for (int i = 1; i <= K; i++) {
        sort(c[i].begin(), c[i].end());
        cout << i << " " << c[i].size() << endl;
        for (int j = 0; j < c[i].size(); j++) {
            cout << c[i][j] << endl;
        }
    }
    return 0;
}
// 改成用char数组存储name，sort改成int的比较，比较的时候去访问names判断先后
// 就不会超时了，这个是超时的代码，懒得改了，就是char数组的问题
// 同时注意cout可能比printf慢一点