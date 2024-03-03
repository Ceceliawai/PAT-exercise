#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int e[1010][1010],n,m,k;
int t[1010];//�����������ʱ��
int d[1010];//�ҵ���㵽��������·��
bool visited[1010];
vector<int>hispath;
int INF=(0x1)<<30;
int s1,s2;
//��Ϊ�Һ���һ�����٣�������·�����ȴ���ʱ�伴��
//Ҫ����ȥ���ĵط���������������֮ǰ����d��t�Ĳ�������Ǹ���
int main(){
    fill(d,d+1010,INF);
    fill(e[0],e[0]+1010*1010,INF);
    fill(visited,visited+1010,false);
    cin>>n>>m>>k;
    cin>>s1>>s2;
    for(int i=0;i<k;i++){
        int p;
        cin>>p;
        hispath.push_back(p);
    }
    for(int i=0;i<m;i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        e[x][y]=dis;
        e[y][x]=dis;
    }
    int Time=0;
    t[s1]=0;
    int pre=s1;
    for(int i=1;i<hispath.size();i++){
        Time+=e[pre][hispath[i]];
        t[hispath[i]]=Time;
        pre=hispath[i];
    }

    //dijstra
    d[s2]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        int mind=INF;
        for(int i=1;i<=n;i++){
            if(visited[i]==false&&d[i]<mind){
                u=i;
                mind=d[i];
            }
        }
        if(u==-1)break;
        visited[u]=true;
        for(int i=1;i<=n;i++){
            if(e[u][i]!=INF&&d[i]>e[u][i]+d[u]){
                d[i]=e[u][i]+d[u];
            }
        }
    }
    int maxt=-1;
    for(int i=0;i<hispath.size();i++){
        int curp=hispath[i];
        int a=t[curp];
        int b=d[curp];
        if(visited[curp]==true&&t[curp]-d[curp]>maxt){
            maxt=t[curp]-d[curp];
        }
    }
    if(maxt==-1)cout<<"-1";
    else cout<<maxt;
    return 0;
}
