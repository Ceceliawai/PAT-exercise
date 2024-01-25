#include <iostream>
#include <string>
using namespace std;

int C[2001];
int M[2001];
int E[2001];
int A[2001];

void init() {
  for (int i = 0; i < 2001; i++) {
    C[i] = -1;
    M[i] = -1;
    E[i] = -1;
    A[i] = -1;
  }
}

void insert(int val, int flag) {
  if (flag == 0) {
    for (int i = 2000; i >= 0; i--) {
      if (C[i] == -1) {
        if (i == 0)
          C[0] = val;
        else
          continue;
      } else if (val > C[i]) {
        C[i + 1] = C[i];  // 后移一个
        if (i == 0) C[0] = val;
      } else if (val == C[i]) {
        return;  // 不用插入，直接返回
      } else if (val < C[i]) {
        C[i + 1] = val;  // 找到插入的位置
        return;
      }
    }
  }

  if (flag == 2) {
    for (int i = 2000; i >= 0; i--) {
      if (E[i] == -1) {
        if (i == 0)
          E[0] = val;
        else
          continue;
      } else if (val > E[i]) {
        E[i + 1] = E[i];  // 后移一个
        if (i == 0) E[0] = val;
      } else if (val == E[i]) {
        return;  // 不用插入，直接返回
      } else if (val < E[i]) {
        E[i + 1] = val;  // 找到插入的位置
        return;
      }
    }
  }

  if (flag == 1) {
    for (int i = 2000; i >= 0; i--) {
      if (M[i] == -1) {
        if (i == 0)
          M[0] = val;
        else
          continue;
      } else if (val > M[i]) {
        M[i + 1] = M[i];  // 后移一个
        if (i == 0) M[0] = val;
      } else if (val == M[i]) {
        return;  // 不用插入，直接返回
      } else if (val < M[i]) {
        M[i + 1] = val;  // 找到插入的位置
        return;
      }
    }
  }

  if (flag == 3) {
    for (int i = 2000; i >= 0; i--) {
      if (A[i] == -1) {
        if (i == 0)
          A[0] = val;
        else
          continue;
      } else if (val > A[i]) {
        A[i + 1] = A[i];  // 后移一个
        if (i == 0) A[0] = val;
      } else if (val == A[i]) {
        return;  // 不用插入，直接返回
      } else if (val < A[i]) {
        A[i + 1] = val;  // 找到插入的位置
        return;
      }
    }
  }
}

int FindRank(int grade, int flag) {
  if (flag == 0) {
    for (int i = 0; i < 2001 && C[i] != -1; i++) {
      if (grade == C[i]) return i + 1;
    }
  }
  if (flag == 1) {
    for (int i = 0; i < 2001 && M[i] != -1; i++) {
      if (grade == M[i]) return i + 1;
    }
  }
  if (flag == 2) {
    for (int i = 0; i < 2001 && E[i] != -1; i++) {
      if (grade == E[i]) return i + 1;
    }
  }
  if (flag == 3) {
    for (int i = 0; i < 2001 && A[i] != -1; i++) {
      if (grade == A[i]) return i + 1;
    }
  }
  return 2001;
}

int main() {
  int iN, iM;
  cin >> iN >> iM;
  string ids[iN];
  int grade[iN][4];
  init();
  for (int i = 0; i < iN; i++) {
    string id;
    int Cg, Mg, Eg, Ag;
    cin >> id >> Cg >> Mg >> Eg;
    Ag = (Cg + Mg + Eg) / 3;
    ids[i] = id;
    grade[i][0] = Cg;
    grade[i][1] = Mg;
    grade[i][2] = Eg;
    grade[i][3] = Ag;
    insert(Cg, 0);
    insert(Mg, 1);
    insert(Eg, 2);
    insert(Ag, 3);
  }
  string mids[iM];
  for (int i = 0; i < iM; i++) {
    cin >> mids[i];
  }

  for (int i = 0; i < iM; i++) {
    string cur = mids[i];
    int index = -1;
    for (int j = 0; j < iN; j++) {
      if (ids[j] == cur) {
        index = j;
        break;
      }
    }
    if (index == -1) {
      cout << "N/A" << endl;
    } else if (index != -1) {
      int a, b, c, d;
      a = FindRank(grade[index][0], 0);
      b = FindRank(grade[index][1], 1);
      c = FindRank(grade[index][2], 2);
      d = FindRank(grade[index][3], 3);
      int min = 2001;
      int flag = -1;
      if (c <= min) {
        min = c;
        flag = 2;
      }
      if (b <= min) {
        min = b;
        flag = 1;
      }
      if (a <= min) {
        min = a;
        flag = 0;
      }
      if (d <= min) {
        min = d;
        flag = 3;
      }
      cout << min;
      if (flag == 0)
        cout << " C" << endl;
      else if (flag == 1)
        cout << " M" << endl;
      else if (flag == 2)
        cout << " E" << endl;
      else if (flag == 3)
        cout << " A" << endl;
    }
  }
  return 0;
}