#include <iostream>
using namespace std;
int N, M, image[480010], curnum, curcount = 0;
int main() {
    cin >> N >> M;
    curnum = -1;
    for (int i = 0; i < N * M; i++) {
        cin >> image[i];
        if (image[i] != curnum)
            curcount--;
        else
            curcount++;
        if (curcount < 0) {
            curcount = 1;
            curnum = image[i];
        }
    }
    curcount = 0;
    for (int i = 0; i < N * M; i++) {
        if (image[i] == curnum) curcount++;
    }
    if (curcount > N * M / 2) cout << curnum;
    return 0;
}