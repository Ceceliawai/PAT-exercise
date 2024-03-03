#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int len, n, l, r;
typedef struct part {
    int left;
    int right;
} p;
vector<p> parts;
bool mycmp(p p1, p p2) {
    if (p1.left != p2.left) {
        return p1.left < p2.left;
    }
    return p1.right < p2.right;
}
int main() {
    cin >> len >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        l = max(0, l);
        r = min(len - 1, r);
        p np;
        np.left = l;
        np.right = r;
        parts.push_back(np);
    }
    sort(parts.begin(), parts.end(), mycmp);
    int ml, mr;
    ml = parts[0].left;
    mr = parts[0].right;
    bool flag = true;
    for (int i = 1; i < n; i++) {
        l = parts[i].left;
        r = parts[i].right;
        if (l > mr + 1) {
            flag = false;
            break;
        }
        ml = min(ml, l);
        mr = max(mr, r);
    }
    if (ml != 0) flag = false;
    if (mr != len - 1) flag = false;
    if (flag == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}