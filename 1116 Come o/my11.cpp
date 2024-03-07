#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, int> torank;
int N;
bool check[10000];
bool isprime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        torank[num] = i;
    }
    cin >> N;
    fill(check, check + 10000, false);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (torank.count(num) == 0) {
            cout << num << ": Are you kidding?" << endl;
        } else {
            int rank = torank[num];
            if (check[num] == true) {
                printf("%04d", num);
                cout << ": Checked" << endl;
            } else {
                if (isprime(rank) == true) {
                    printf("%04d", num);
                    cout << ": Minion" << endl;
                } else {
                    if (rank == 1) {
                        printf("%04d", num);
                        cout << ": Mystery Award" << endl;
                    } else {
                        printf("%04d", num);
                        cout << ": Chocolate" << endl;
                    }
                }
            }
            check[num] = true;
        }
    }
    return 0;
}