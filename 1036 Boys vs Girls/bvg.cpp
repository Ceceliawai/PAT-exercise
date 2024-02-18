#include <iostream>
#include <string>

using namespace std;

int maxg = -1;
int ming = 101;

typedef struct student {
    string name;
    string ID;
} stu;

stu Man;
stu Fem;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b;
        int c;
        char G;
        cin >> a >> G >> b >> c;
        if (G == 'M' && c < ming) {
            Man.name = a;
            Man.ID = b;
            ming = c;
        }
        if (G == 'F' && c > maxg) {
            Fem.name = a;
            Fem.ID = b;
            maxg = c;
        }
    }

    if (maxg == -1) {
        cout << "Absent" << endl;
    } else {
        cout << Fem.name << " " << Fem.ID << endl;
    }

    if (ming == 101) {
        cout << "Absent" << endl;
    } else {
        cout << Man.name << " " << Man.ID << endl;
    }

    if (ming == 101 || maxg == -1)
        cout << "NA";
    else
        cout << maxg - ming << endl;
    return 0;
}