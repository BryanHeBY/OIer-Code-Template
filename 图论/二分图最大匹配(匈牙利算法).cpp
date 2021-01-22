#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct edge{int next,to;}e[N*N];
int num_edge,head[N];
void add_edge(int from,int to)
{
    e[++num_edge]=(edge){head[from],to};
    head[from]=num_edge;
}

int n,k,m;
void init();
void solve();

bool view[N];
int match[N];
bool dfs(int);//匈牙利算法
int ans;

int main()
{
    init();
    solve();
    cout<<ans;
    return 0;
}
void init()
{
    cin>>n>>k>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(y>k)continue;
        add_edge(x,y);
    }
}
bool dfs(int x)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int y=e[i].to;
        if(view[y])continue;//保证复杂度
        view[y]=1;
        if(!match[y]||dfs(match[y]))
        {
            match[y]=x;
            return 1;
        }//尝试寻找增广路
    }
    return 0;
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        memset(view,0,sizeof(view));//先清空
        ans+=dfs(i);
    }
}