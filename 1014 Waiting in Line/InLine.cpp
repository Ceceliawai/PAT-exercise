#include <stdio.h>

#include <iostream>
using namespace std;

typedef struct queue {
  int array[10];  // 循环队列
  int front;      // 队头
  int rear;       // 队尾
  int size;       // 判断队空还是满
} Queue;

Queue Ques[21];         // 队列
int needtime[1001];     // 完成服务需要的时间
int finishtime[1001];   // 完成服务的时刻
int starttime[1001];    // 开始服务的时刻
int outputindex[1001];  // 需要输出的下标

void Init(Queue &Q) {
  Q.front = 0;
  Q.rear = 0;  // 先入队再增
  Q.size = 0;
}

// 入队
void Enqueue(Queue &Q, int key) {
  // 在主函数中判断 队不够时不会使用这个函数
  Q.array[Q.rear] = key;
  Q.size++;
  Q.rear = (Q.rear + 1) % 10;
}

// 出队
int Dequeue(Queue &Q) {
  int res = Q.array[Q.front];
  Q.size--;
  Q.front = (Q.front + 1) % 10;
  return res;
}

void turntotime(int min) {
  int hour = min / 60 + 8;
  int minitue = min % 60;
  printf("%02d", hour);
  cout << ':';
  printf("%02d", minitue);
  cout << endl;
  return;
}

int main() {
  // 处理输入
  int M, N, K, Q;
  cin >> N >> M >> K >> Q;
  // N个窗口 最多M个人 有K个人要来 Q个人要输出
  for (int i = 0; i < K; i++) {
    cin >> needtime[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> outputindex[i];
  }

  for (int i = 0; i < N; i++) {  // 初始化
    Init(Ques[i]);
  }
  // 最开始是一起到的，先把窗口排满
  int j = 0;
  int inlinecount = 0;  // 在线里的数量
  int leftcount = K;    // 剩余的没排进去的数量
  int totalcount = 0;
  int timenow = 0;  // 已经过去的时间
  for (int i = 0; i < N * M && i < K;
       i++) {  // 相当于依次排过去，用i限制队列size
    Enqueue(Ques[j], i);
    j = (j + 1) % N;
    inlinecount++;
    leftcount--;
    totalcount++;
  }
  for (int i = 0; i < N; i++) {
    starttime[Ques[i].array[Ques[i].front]] = 0;
  }

  while (inlinecount != 0) {  // 还有人没结束
    // 找到最快结束的那个输出，并更新其它队头的needtime
    int min = 99999999;
    int minindex = -1;
    for (int i = 0; i < N; i++) {
      if (Ques[i].size != 0 && needtime[Ques[i].array[Ques[i].front]] < min) {
        min = needtime[Ques[i].array[Ques[i].front]];
        minindex = i;
      }
    }
    int outindex = Dequeue(Ques[minindex]);
    int mintime = needtime[outindex];
    timenow = timenow + needtime[outindex];
    finishtime[outindex] = timenow;
    if (Ques[minindex].size != 0) {
      starttime[Ques[minindex].array[Ques[minindex].front]] = timenow;
    }  // 删除的那个队伍有一个新的客人正在被服务
    inlinecount--;
    for (int i = 0; i < N; i++) {
      if (i != minindex && Ques[i].size != 0) {
        needtime[Ques[i].array[Ques[i].front]] -= mintime;
      }
    }

    // 如果还有没入队的找个地方入队
    if (leftcount != 0) {
      Enqueue(Ques[minindex], totalcount);
      if (Ques[minindex].size == 1) {
        starttime[Ques[minindex].array[Ques[minindex].front]] = timenow;
        // 入队之后只有一个，说明入队之后就直接被服务了开始
      }
      totalcount++;
      leftcount--;
      inlinecount++;
    }
  }

  for (int i = 0; i < Q; i++) {
    if (starttime[outputindex[i] - 1] < 540)
      turntotime(finishtime[outputindex[i] - 1]);
    else {
      cout << "Sorry" << endl;
    }
  }
  return 0;
}