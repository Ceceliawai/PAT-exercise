#include <iostream>
#include <string>
#include <vector>

using namespace std;

int modified_num = 0;  // 被修改的账户的数目

vector<string> res_name;  // 被修改的账户的用户名
vector<string> res_pass;  // 被修改的账户的密码

int N;

int main() {
    cin >> N;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        string name, pass;
        cin >> name >> pass;
        bool m = false;
        for (int j = 0; j < pass.size(); j++) {
            switch (pass[j]) {
                case '1':
                    pass[j] = '@';
                    m = true;
                    break;
                case '0':
                    pass[j] = '%';
                    m = true;
                    break;
                case 'l':
                    pass[j] = 'L';
                    m = true;
                    break;
                case 'o':
                    pass[j] = 'O';
                    m = true;
                    break;
            }
        }
        if (m == true) {
            res_name.push_back(name);
            res_pass.push_back(pass);
            flag = true;
            modified_num++;
        }
    }

    if (flag == false) {
        cout << "There are " << N << " accounts and no account is modified"
             << endl;
        return 0;
    }

    cout << modified_num << endl;
    for (int i = 0; i < modified_num; i++) {
        cout << res_name[i];
        cout << " ";
        cout << res_pass[i];
        cout << endl;
    }
    return 0;
}