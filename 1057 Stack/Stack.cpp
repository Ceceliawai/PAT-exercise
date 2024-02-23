#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> nums;
vector<string> res;
int S[100010], N, val, index, Ssize = 0;
int main() {
    cin >> N;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str == "Pop") {
            if (Ssize == 0) {
                res.push_back("Invalid");
            } else {
                res.push_back(to_string(S[Ssize - 1]));
                auto it = find(nums.begin(), nums.end(), S[Ssize - 1]);
                nums.erase(it);
                Ssize--;
            }
        } else if (str == "Push") {
            cin >> val;
            S[Ssize] = val;
            nums.push_back(val);
            Ssize++;
        } else if (str == "PeekMedian") {
            if (Ssize == 0) {
                res.push_back("Invalid");
            } else {
                sort(nums.begin(), nums.end());
                // 使用sort会导致运行超时，想别的办法实现这个东西
                if (nums.size() % 2 == 0) {
                    index = nums.size() / 2;
                } else
                    index = (nums.size() + 1) / 2;
                res.push_back(to_string(nums[index - 1]));
            }
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}