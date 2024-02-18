#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long int> cp;  // 正数coupon
vector<long long int> c0;  // 0coupon
vector<long long int> cn;  // 负数coupon
vector<long long int> pp;  // 正数product
vector<long long int> p0;  // 0 product
vector<long long int> pn;  // 负数product

int Nc, Np;

bool cmp(long long int a, long long int b) { return a >= b; }

int main() {
    cin >> Nc;
    for (int i = 0; i < Nc; i++) {
        long long int key;
        cin >> key;
        if (key > 0)
            cp.push_back(key);
        else if (key < 0)
            cn.push_back(key);
        else
            c0.push_back(key);
    }

    cin >> Np;
    for (int i = 0; i < Np; i++) {
        long long int key;
        cin >> key;
        if (key > 0)
            pp.push_back(key);
        else if (key < 0)
            pn.push_back(key);
        else
            p0.push_back(key);
    }

    sort(cp.begin(), cp.end(), cmp);
    sort(cn.begin(), cn.end(), cmp);
    sort(pp.begin(), pp.end(), cmp);
    sort(pn.begin(), pn.end(), cmp);

    if (cp.size() == 0 && pp.size() == 0 && cn.size() != 0 && pn.size() != 0) {
        // 全是负数
        long long int val = 0;
        for (int i = 0; i < cn.size() && i < pn.size(); i++) {
            val += cn[cn.size() - 1 - i] * pn[pn.size() - 1 - i];
        }
        cout << val;
        return 0;
    } else if (cn.size() == 0 && pn.size() == 0 && cp.size() != 0 &&
               pp.size() != 0) {
        // 全是正数
        long long int val = 0;
        for (int i = 0; i < cp.size() && i < pp.size(); i++) {
            val += cp[i] * pp[i];
        }
        cout << val;
        return 0;
    } else if (cn.size() == 0 && pn.size() != 0 && cp.size() != 0 &&
               pp.size() == 0) {
        // 一正一负
        if (c0.size() != 0 || cp.size() != 0) {
            cout << "0";
            return 0;
        }
        cout << cp[cp.size() - 1] * pn[0];
        return 0;
    } else if (cn.size() != 0 && pn.size() == 0 && cp.size() == 0 &&
               pp.size() != 0) {
        // 一正一负
        if (c0.size() != 0 || cp.size() != 0) {
            cout << "0";
            return 0;
        }
        cout << pp[pp.size() - 1] * cn[0];
        return 0;
    } else if (cn.size() == 0 && pn.size() == 0 && cp.size() == 0 &&
               pp.size() == 0) {
        cout << "0";
        return 0;
    } else {
        // 有正有负
        long long int val = 0;
        for (int i = 0; i < cp.size() && i < pp.size(); i++) {
            val += cp[i] * pp[i];
        }
        for (int i = 0; i < cn.size() && i < pn.size(); i++) {
            val += cn[cn.size() - 1 - i] * pn[pn.size() - 1 - i];
        }
        cout << val;
        return 0;
    }
}