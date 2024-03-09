#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    priority_queue<double, vector<double>, greater<double> > q;
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        double a = q.top();
        q.pop();
        double b = q.top();
        q.pop();
        q.push((a + b) / 2);
    }
    int res = q.top();
    cout << res;
    return 0;
}