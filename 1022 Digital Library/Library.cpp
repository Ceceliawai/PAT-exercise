#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, M;

typedef struct BookInfo {
    string title;
    string author;
    vector<string> keywords;  // no more than 5 keywords
    string publisher;
    string year;
} BookInfo;

map<int, BookInfo> Library;  // all the books
vector<int> IDs;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int ID;
        string s;
        cin >> ID;  // ID
        BookInfo newbook;
        getchar();
        getline(cin, s);  // title
        newbook.title = s;
        getline(cin, s);  // author
        newbook.author = s;
        getline(cin, s);  // keywords
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                temp += s[i];
            else {
                newbook.keywords.push_back(temp);
                temp = "";
            }
        }
        newbook.keywords.push_back(temp);  // the last keyword
        getline(cin, s);                   // publisher
        newbook.publisher = s;
        getline(cin, s);  // year
        newbook.year = s;
        Library.insert(make_pair(ID, newbook));
        IDs.push_back(ID);
    }

    cin >> M;
    getchar();
    string query[M];
    for (int i = 0; i < M; i++) {
        getline(cin, query[i]);
    }
    for (int i = 0; i < M; i++) {
        int flag;
        int j;
        flag = query[i][0] - '0';
        string s = query[i].substr(3);
        vector<int> res;
        res.clear();
        for (int i = 0; i < IDs.size(); i++) {
            switch (flag) {
                case 1:  // title
                    if (Library[IDs[i]].title.find(s) != string::npos) {
                        res.push_back(IDs[i]);
                    }
                    break;
                case 2:
                    if (Library[IDs[i]].author == s) {
                        res.push_back(IDs[i]);
                    }
                    break;
                case 3:
                    if (count(Library[IDs[i]].keywords.begin(),
                              Library[IDs[i]].keywords.end(), s) != 0) {
                        res.push_back(IDs[i]);
                    }
                    break;
                case 4:
                    if (Library[IDs[i]].publisher == s) {
                        res.push_back(IDs[i]);
                    }
                    break;
                case 5:
                    if (Library[IDs[i]].year == s) {
                        res.push_back(IDs[i]);
                    }
                    break;
            }
        }
        cout << flag << ": " << s << endl;
        if (res.size() != 0) {
            sort(res.begin(), res.end());
            for (int i = 0; i < res.size(); i++) {
                printf("%07d\n", res[i]);
            }
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}
