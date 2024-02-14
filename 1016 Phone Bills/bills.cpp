#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

enum type { ON_LINE, OFF_LINE, NULL_LINE };

typedef struct Record {
  enum type rtype;
  int month;
  int day;
  int hour;
  int mintue;
  string name;
} record;

typedef struct User {
  string name;
  record records[500][2];
  int size;
} user;

record recs[1000];
user myuser[500];
int usercount = 0;
int price[24];

bool mycmp(record r1, record r2) {
  if (r1.name != r2.name) return r1.name < r2.name;
  if (r1.day != r2.day) return r1.day < r2.day;
  if (r1.hour != r2.hour) return r1.hour < r2.hour;
  if (r1.mintue != r2.mintue) return r1.mintue < r2.mintue;
  return false;
}

double calculate_price(record r1, record r2) {
  if (r1.day == r2.day) {
    if (r1.hour == r2.hour) {
      return (r2.mintue - r1.mintue) * price[r1.hour] / 100.0;
    } else {
      double sum = 0;
      sum += (60 - r1.mintue) * price[r1.hour] / 100.0;
      for (int i = r1.hour + 1; i < r2.hour; i++) {
        sum += price[i] * 60 / 100.0;
      }
      sum += r2.mintue * price[r2.hour] / 100.0;
      return sum;
    }
  } else {
    double sum = 0;
    sum += (60 - r1.mintue) * price[r1.hour] / 100.0;  // 当前小时
    for (int i = r1.hour + 1; i <= 23; i++) {
      sum += price[i] * 60 / 100.0;
    }
    double total = 0;
    for (int j = 0; j < 24; j++) {
      total += price[j];
    }
    sum += (r2.day - r1.day - 1) * total * 60 / 100.0;
    for (int i = 0; i < r2.hour; i++) {
      sum += price[i] * 60 / 100.0;
    }
    sum += r2.mintue * price[r2.hour] / 100.0;
    return sum;
  }
}
int calculate_time(record r1, record r2) {
  if (r1.day == r2.day) {
    if (r1.hour == r2.hour) {
      return r2.mintue - r1.mintue;
    } else {
      return 60 - r1.mintue + r2.mintue + (r2.hour - r1.hour - 1) * 60;
    }
  } else {
    return 60 - r1.mintue + (23 - r1.hour) * 60 + r2.mintue + (r2.hour) * 60 +
           (r2.day - r1.day - 1) * 60 * 24;
  }
}

int main() {
  for (int i = 0; i < 24; i++) {
    cin >> price[i];
  }
  int N;
  cin >> N;
  // 处理输入
  for (int i = 0; i < N; i++) {
    char n[21];  // name
    int m;       // month
    int d;       // day
    int h;       // hour
    int mi;      // mintue
    char t[9];   // type
    scanf("%s%d:%d:%d:%d%s", n, &m, &d, &h, &mi, t);
    record r;
    r.name = n;
    r.month = m;
    r.day = d;
    r.hour = h;
    r.mintue = mi;
    if (t[1] == 'n')
      r.rtype = ON_LINE;
    else
      r.rtype = OFF_LINE;
    recs[i] = r;
  }

  sort(recs, recs + N, mycmp);

  for (int i = 0; i < N; i++) {
    record prev = recs[i];
    if (prev.rtype == OFF_LINE) {
      continue;
      // 跳过，OFFLINE的配对只能在前面找不可能在后面找
      // 因此如果prev是OFFline的话说明它一定没有配对的
    } else {
      // 找到配对的那个
      for (int j = i + 1; j < N; j++) {
        record cur = recs[j];
        if (cur.name == prev.name) {
          if (prev.rtype == ON_LINE && cur.rtype == OFF_LINE) {
            // 找到一对配对的
            if (usercount == 0) {
              myuser[0].name = prev.name;
              myuser[0].records[0][0] = prev;
              myuser[0].records[0][1] = cur;
              myuser[0].size++;
              usercount++;
              break;  // 处理结束
            } else {
              int k;
              for (k = 0; k < usercount; k++) {
                if (myuser[k].name == prev.name) {
                  myuser[k].records[myuser[k].size][0] = prev;
                  myuser[k].records[myuser[k].size][1] = cur;
                  myuser[k].size++;
                  break;
                }
              }  // end for
              if (k == usercount) {
                // 没找到，新加一个user
                myuser[usercount].name = prev.name;
                myuser[usercount].records[0][0] = prev;
                myuser[usercount].records[0][1] = cur;
                myuser[usercount].size++;
                usercount++;
              }
              break;  // 处理结束，跳出j的for循环
            }         // end else
          }           // end if
          else if (cur.rtype == ON_LINE) {
            // 按照最近的配对，两个连在一起的ONLINE，
            break;  // 跳出j的for循环
          }
        }  // end name equal if
      }    // end for
    }
  }

  // 开始计算价格
  for (int i = 0; i < usercount; i++) {
    double sum = 0;
    cout << myuser[i].name;
    cout << " ";
    printf("%02d", myuser[i].records[0][0].month);
    cout << endl;
    for (int j = 0; j < myuser[i].size; j++) {
      printf("%02d", myuser[i].records[j][0].day);
      cout << ":";
      printf("%02d", myuser[i].records[j][0].hour);
      cout << ':';
      printf("%02d", myuser[i].records[j][0].mintue);
      cout << ' ';
      printf("%02d", myuser[i].records[j][1].day);
      cout << ":";
      printf("%02d", myuser[i].records[j][1].hour);
      cout << ':';
      printf("%02d", myuser[i].records[j][1].mintue);
      int lastingtime =
          calculate_time(myuser[i].records[j][0], myuser[i].records[j][1]);
      double partprice =
          calculate_price(myuser[i].records[j][0], myuser[i].records[j][1]);
      cout << ' ' << lastingtime;
      cout << " $";
      printf("%.2f", partprice);
      sum += partprice;
      cout << endl;
    }
    cout << "Total amount: $";
    printf("%.2f", sum);
    cout << endl;
  }

  return 0;
}
