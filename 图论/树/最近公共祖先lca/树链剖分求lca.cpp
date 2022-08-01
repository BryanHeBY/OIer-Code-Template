#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{int next,to;}e[2*N];
int head[N],num_edge;
void add_edge(int from,int to){e[++num_edge]=(edge){head[from],to},head[from]=num_edge;}

struct TC
{
    int fa[N],size[N],wson[N],dfn[N],now,top[N];
    void dfs1(int x)
    {
        size[x]=1;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(y==fa[x])continue;
            fa[y]=x;dfs1(y);
            size[x]+=size[y];
            if(size[y]>size[wson[x]])wson[x]=y;
        }
    }
    void dfs2(int x,int topf)
    {
        dfn[x]=++now,top[x]=topf;
        if(!wson[x])return;
        dfs2(wson[x],topf);
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(y!=fa[x]&&y!=wson[x])dfs2(y,y);
        }
    }
    void div(int root){dfs1(root),dfs2(root,root);}
    int query(int x,int y)
    {
        while(top[x]!=top[y])
        {
            if(dfn[top[x]]<dfn[top[y]])swap(x,y);
            x=fa[top[x]];
        }
        if(dfn[x]>dfn[y])swap(x,y);
        return x;
    }
}T;

int n,m,s;

int main()
{
    scanf("%d%d%d",&n,&m,&s);
	int x,y;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y),add_edge(y,x);
	}
	T.div(s);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",T.query(x,y));
	}
    return 0; 
} 