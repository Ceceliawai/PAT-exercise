#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
int mydata[1000000], pointer[1000000];
using namespace std;
vector<int> adds;
bool mycmp(int a, int b) { return mydata[a] < mydata[b]; }
int main() {
    int N, curad, curdata, nextad, headad;
    cin >> N >> headad;
    for (int i = 0; i < N; i++) {
        cin >> curad >> curdata >> nextad;
        mydata[curad] = curdata;
        pointer[curad] = nextad;
    }
    curad = headad;
    while (curad != -1) {
        adds.push_back(curad);
        curad = pointer[curad];
    }
    if (adds.size() == 0) {
        cout << "0 -1" << endl;
        return 0;
    }
    sort(adds.begin(), adds.end(), mycmp);
    cout << adds.size() << " ";
    if (adds.size() != 0) printf("%05d\n", adds[0]);
    for (int i = 0; i < adds.size(); i++) {
        curad = adds[i];
        curdata = mydata[curad];
        if (i != adds.size() - 1)
            nextad = adds[i + 1];
        else
            nextad = -1;
        if (nextad != -1)
            printf("%05d %d %05d\n", curad, curdata, nextad);
        else
            printf("%05d %d -1\n", curad, curdata);
    }
    return 0;
}