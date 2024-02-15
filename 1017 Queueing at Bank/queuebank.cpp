#include <algorithm>
#include <iostream>

using namespace std;

typedef struct myTime {
  int hour;
  int minute;
  int second;
} mytime;

typedef struct customer {
  mytime arrive;
  int needtime;
  // int waittime;
} cus;

cus customers[10000];

bool mycmp(cus c1, cus c2) {
  if (c1.arrive.hour != c2.arrive.hour) return c1.arrive.hour < c2.arrive.hour;
  if (c1.arrive.minute != c2.arrive.minute)
    return c1.arrive.minute < c2.arrive.minute;
  if (c1.arrive.second != c2.arrive.second)
    return c1.arrive.second < c2.arrive.second;
  return false;
}

bool cmptime(mytime t1, mytime t2) {
  if (t1.hour != t2.hour) return t1.hour < t2.hour;
  if (t1.minute != t2.minute) return t1.minute < t2.minute;
  if (t1.second != t2.second) return t1.second < t2.second;
  return false;
}

mytime addtime(mytime t1, int m) {
  mytime res;
  res.second = t1.second;
  res.minute = t1.minute + m % 60;
  if (res.minute >= 60) {
    // 考虑分钟进位
    res.minute = res.minute % 60;
    res.hour = m / 60 + t1.hour + 1;
  } else
    res.hour = m / 60 + t1.hour;
  return res;
}

double timeval(mytime t1, mytime t2) {
  return (t2.hour - t1.hour - 1) * 60 * 60 +
         (t2.minute + 60 - t1.minute - 1) * 60 + t2.second + (60 - t1.second);
}

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int h, m, s, needt;
    scanf("%d:%d:%d %d", &h, &m, &s, &needt);
    customers[i].arrive.hour = h;
    customers[i].arrive.minute = m;
    customers[i].arrive.second = s;
    customers[i].needtime = needt;
  }
  sort(customers, customers + N, mycmp);
  mytime overtime[K];
  mytime starttime;
  starttime.hour = 8;
  starttime.minute = 0;
  starttime.second = 0;

  mytime latest;
  latest.hour = 17;
  latest.minute = 0;
  latest.second = 1;
  for (int i = 0; i < K; i++) {
    // 初始化
    overtime[i] = starttime;
  }

  double sum = 0;
  int count = 0;

  for (int i = 0; i < N; i++) {
    mytime min = overtime[0];
    int index = 0;
    for (int j = 1; j < K; j++) {
      // 找到等待时间最短的那个去窗口处理
      if (cmptime(overtime[j], min)) {
        min = overtime[j];
        index = j;
      }
    }

    if (cmptime(customers[i].arrive, latest) == false) {
      break;  // 到达的就晚了，不计算在平均时间内
    }
    count++;
    if (cmptime(customers[i].arrive, overtime[index])) {  // 到了但还没有空窗口
      double t = timeval(customers[i].arrive, overtime[index]);
      sum += t;
      overtime[index] =
          addtime(overtime[index], customers[i].needtime);  // 更新窗口空闲时间
    } else {
      sum += 0;  // 不用等
      overtime[index] = addtime(customers[i].arrive, customers[i].needtime);
    }
  }

  if (count == 0) {
    printf("0.0");
    return 0;
  }
  sum = sum * 1.0 / count / 60;
  printf("%.1f", sum);
  return 0;
}
