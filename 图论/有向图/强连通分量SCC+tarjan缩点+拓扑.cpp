#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e5+5;

struct edge{int next,to;}e[M];
int head[N],num_edge;
void add_edge(int,int);

struct cedge{int next,to;}ce[M];
int chead[N],cnum_edge;
void cadd_edge(int,int);

int n,m;
void init();

int sta[N],top;
bool ins[N];
int dfn[N],low[N],now;
int c[N],tot;
void tarjan(int);//tarjan
void draw();//缩点

int ind[N];
void topo();//拓扑

int main()
{
	init();
	draw();
	topo();
	return 0;
}

void add_edge(int from,int to)
{
	e[++num_edge]=(edge){head[from],to};
	head[from]=num_edge;
}
void cadd_edge(int from,int to)
{
	ce[++cnum_edge]=(cedge){chead[from],to};
	chead[from]=cnum_edge;
}
void init()
{
	cin>>n>>m;
	int x,y;
	while(m--)
	{
		cin>>x>>y;
		add_edge(x,y);
	}
}
void tarjan(int x)//求出了反向拓扑序
{
	dfn[x]=low[x]=++now;
	sta[++top]=x,ins[x]=1;//捆绑入栈，标记
	for(int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(ins[y])
			low[x]=min(low[x],dfn[y]);
            //保证在栈中，有横叉边
	}
	if(dfn[x]==low[x])//若无法回到祖先
	{
		int y;
		tot++;
		do
		{
			y=sta[top--];ins[y]=0;
            //捆绑出栈，取标记
			c[y]=tot;
		}while(y!=x);
	}
}
void draw()
{
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int x=1;x<=n;x++)
		for(int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if(c[x]!=c[y])
			{
				cadd_edge(c[x],c[y]);
				ind[c[y]]++;
			}
		}
}
void topo()
{
	for(int i=1;i<=tot;i++)
		if(!ind[i])sta[++top]=i;
	while(top)
	{
		int x=sta[top--];
		for(int i=chead[x];i;i=ce[i].next)
		{
			int y=ce[i].to;
			//do something
			if(!(--ind[y]))sta[++top]=y;
		}
	}
}
