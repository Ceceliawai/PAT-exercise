#include <algorithm>
#include <iostream>

using namespace std;

int N;                 // number of participants
int numcount[10001];   // count of the number occurs
int inputnum[100000];  // the input number

int main() {
    cin >> N;
    fill(numcount, numcount + 10001, 0);
    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;
        numcount[key]++;
        inputnum[i] = key;
    }

    int index = -1;
    for (int i = 0; i < N; i++) {
        if (numcount[inputnum[i]] == 1) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << inputnum[index];
    else
        cout << "None";
    return 0;
}