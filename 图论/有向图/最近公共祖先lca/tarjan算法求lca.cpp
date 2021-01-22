#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

struct edge{int next,to;}e[N];
int head[N],num_edge;
void add_edge(int from,int to){e[++num_edge]=(edge){head[from],to};head[from]=num_edge;}

struct que{int next,b;}q[N];
int num_que=1,headq[N];
void add_que(int a,int b){q[++num_que]=(que){headq[a],b};headq[a]=num_que;}

int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int n,m,root;
void init(),solve();


void tarjan(int,int);
int ans[N];

int main()
{
    init();
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}

void tarjan(int x,int f)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int y=e[i].to;
        if(y!=f)
        {
            tarjan(y,x);
            fa[y]=x;
        }
    }
    for(int i=headq[x];i;i=q[i].next)
            if(fa[q[i].b]!=q[i].b)ans[i/2]=find(q[i].b);
}	
void init()
{
    scanf("%d%d%d",&n,&m,&root);
    for(int i=1;i<=n;i++)fa[i]=i;
    int x,y;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&x,&y);
        add_edge(x,y),add_edge(y,x);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add_que(x,y),add_que(y,x);
    }
    tarjan(root,0);
}