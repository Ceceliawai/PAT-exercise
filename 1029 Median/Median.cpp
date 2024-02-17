#include <iostream>

using namespace std;

long int s1[200000];
long int s2[200000];
long int s[400000];

int l1, l2, l3;
int i, j, k;

int main() {
    cin >> l1;
    for (int m = 0; m < l1; m++) {
        cin >> s1[m];
    }
    cin >> l2;
    for (int m = 0; m < l2; m++) {
        cin >> s2[m];
    }

    i = j = k = 0;
    while (i < l1 && j < l2) {
        int a = s1[i];
        int b = s2[j];
        if (a < b) {
            s[k] = a;
            i++;
            k++;
        } else if (a > b) {
            s[k] = b;
            j++;
            k++;
        } else if (a == b) {
            s[k] = a;
            i++;
            j++;
            k++;
        }
    }

    // s1还剩
    while (i < l1) {
        s[k++] = s1[i++];
    }
    // s2还剩
    while (j < l2) {
        s[k++] = s2[j++];
    }

    if (k % 2 == 0) {
        cout << s[k / 2 - 1];
    } else
        cout << s[k / 2];
}