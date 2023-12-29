/*
  A+B for polynomials 即对应相加
  我是不是想的太复杂了，都用上map了，算法笔记用的是数组
 */
#include <stdio.h>

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
struct polynomials {
  int count;
  map<int, float> num;
};
typedef struct polynomials poly;

void init(poly& p) {
  p.count = 0;
  p.num.clear();
}

int input(poly& p) {
  int count;
  cin >> count;
  p.count = count;
  int max = -1;
  for (int i = 0; i < count; i++) {
    int index;
    float c;
    cin >> index;
    if (index > max) max = index;
    cin >> c;
    if (p.num.count(index) != 0)
      p.num[index] += c;
    else
      p.num.insert(make_pair(index, c));
  }
  return max;
}
int main() {
  poly a, b;
  init(a);
  init(b);
  int am = input(a);
  int bm = input(b);
  int count = 0;
  int i;
  if (am > bm)
    i = am;
  else
    i = bm;
  // start to compare and compute
  map<int, float> res;
  res.clear();
  for (i; i >= 0; i--) {
    float f = 0;
    if (a.num.count(i) != 0) {
      f += a.num[i];
    }
    if (b.num.count(i) != 0) {
      f += b.num[i];
    }
    if (f != 0) res.insert(make_pair(i, f));
  }
  cout << res.size();
  if (res.size() != 0) {
    map<int, float>::iterator it = res.end();
    it--;
    for (it; it != res.begin(); it--) {
      cout << ' ';
      cout << it->first;
      cout << ' ';
      printf("%.1f", it->second);
    }
    cout << ' ';
    cout << it->first;
    cout << ' ';
    printf("%.1f", it->second);
  }
}