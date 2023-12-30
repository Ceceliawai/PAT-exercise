#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101]; // 每个vector存该点的孩子的数量
int d[101] = {0};

int dfs(int index, int depth)
{
    int maxd = 0;
    if (v[index].size() == 0)
    {
        d[depth]++;
        return depth;
    }

    for (vector<int>::iterator it = v[index].begin(); it != v[index].end(); it++)
    {
        int c = dfs(*it, depth + 1);
        if (c > maxd) // 所有子树里面最高的那个就是它的高度
            maxd = c; // 其实这里应该是c+1，但因为后面改成<=了所以不+1了
    }

    return maxd;
}

int main()
{
    int N, M;
    cin >> N >> M;
    if (N == 0 || M >= N)
        return 0;
    for (int i = 0; i < M; i++)
    {
        int ID, K;
        cin >> ID >> K;
        for (int j = 0; j < K; j++)
        {
            int c;
            cin >> c;
            v[ID].push_back(c);
        }
    }
    int maxd = 0;
    maxd = dfs(1, 0);

    for (int i = 0; i <= maxd; i++)
    {
        if (i != 0)
            cout << ' ';
        cout << d[i];
    }
}