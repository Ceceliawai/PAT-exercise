#include <algorithm>
#include <iostream>
using namespace std;
int N;
int days[100010];
bool mycmp(int a,int b){
    return a>b;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> days[i];
    }
    sort(days + 1, days + 1 + N,mycmp);
    int i=1;
    while(days[i]>i)i++;
    cout<<i-1;
}