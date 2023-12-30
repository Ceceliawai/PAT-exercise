#include <iostream>
const int INF = 9999999;
using namespace std;

int main()
{
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;  // 第一行输入
    int path[N][N];             // 记录两个城市之间的距离
    for (int i = 0; i < N; i++) // 初始化
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = INF;
        }
    }
    int teamnum[N]; // 记录城市的救援队数目
    for(int i=0;i<N;i++)teamnum[i]=0;
    for (int i = 0; i < N; i++)
    { // 第二行输入
        int a;
        cin >> a;
        teamnum[i] = a;
    }
    for (int i = 0; i < M; i++)
    { // 处理以后输入，形成邻接矩阵
        int a, b, c;
        cin >> a >> b >> c;
        path[a][b] = c;
        path[b][a] = c;
    }

    int w[N];             // 最短路径累积的最大城市救援数目
    for(int i=0;i<N;i++)w[i]=0;
    int dis[N];                 // C1点到某点的最短距离
    for (int i = 0; i < N; i++) // 初始化
        dis[i] = INF;
    int num[N];          // 距离最短的路径条数
    for(int i=0;i<N;i++)num[i]=0;
    bool visited[N]; // 该点是否被访问过，即是否已经加入集合中
    for(int i=0;i<N;i++)visited[i]=false;
    dis[C1] = 0;               // 初始化
    num[C1] = 1;
    w[C1] = teamnum[C1];

    // dijkstra算法开始
    for (int i = 0; i < N; i++)
    { // 重复n次的外循环，i只用于计数
        int index = -1;
        int min = INF;
        for (int j = 0; j < N; j++)
        {
            if (visited[j] == false && dis[j] < min)
            { // 找到到起始点距离最短的但还没加入集合的点
                min = dis[j];
                index = j;
            }
        }
        if (index == -1)
            break; // 已经没有距离小于INF的点了，即所有的路径都找到了
        // index!=-1 即找到了一个点可以加入到集合中
        visited[index] = true;
        for (int j = 0; j < N; j++)
        {                                                     // 以index这个点为跳板，看能否更新起始点到其他点的最短路径
            if (visited[j] == false && path[index][j] != INF) // 特别注意这一句，已经visited的就是找到了最短路的点，不用再找他们的了
            {
                if (dis[index] + path[index][j] < dis[j])
                {                                         // 以此点为中点的路径更短
                    dis[j] = dis[index] + path[index][j]; // 更新最短路径
                    w[j] = w[index] + teamnum[j];         // 到index最多的救援队数目加上j本身的等于到j的最多的
                    num[j] = num[index];                  // 只能以index为中点，所以数量就是到index的最短路的数量
                }
                else if (dis[index] + path[index][j] == dis[j])
                {                         // 与当前最短路相等
                    num[j] += num[index]; // 数量是本身加上到index的路径数量
                    if (w[j] < w[index] + teamnum[j])
                        w[j] = w[index] + teamnum[j]; // 只保留最大的那条路径的救援队数量
                }
            }
        }
    }

    cout << num[C2] << ' ' << w[C2];
}
