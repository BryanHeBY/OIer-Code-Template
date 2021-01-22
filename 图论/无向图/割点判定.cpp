#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;

struct edge{int next,to;}e[2*M];
int head[N],num_edge=1;
void add_edge(int,int);

int n,m;
void init();

int dfn[N],low[N],now=0;
int root,cnt;
bool cut[N];
void tarjan(int,int);
void solve();

int main()
{
    init();
    solve();
    return 0;
}

void add_edge(int from,int to)
{
    e[++num_edge]=(edge){head[from],to};
    head[from]=num_edge;
}
void init()
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
        {
        	root=i;
        	tarjan(i,0);
        }
}
void tarjan(int x,int in_edge)
{
    dfn[x]=low[x]=++now;
    int flag=0;
    for(int i=head[x];i;i=e[i].next)
    {
        if(!dfn[e[i].to])
        {
            tarjan(e[i].to,i);
            low[x]=min(low[x],low[e[i].to]);
            if(dfn[x]<=low[e[i].to])flag++;
        }
        else if(i!=(in_edge^1)/*防止访问父节点*/)low[x]=min(low[x],dfn[e[i].to]);
    }
   	if(x!=root&&flag>=1||flag>=2)cut[x]=1,cnt++;
      /*割点判定：戳[父]<=追溯[子]
      	1.x为树根：至少需有两个满足
          2.x非树根：至少要有一个满足
      */
}
void solve()
{
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
        if(cut[i])cout<<i<<" ";
}