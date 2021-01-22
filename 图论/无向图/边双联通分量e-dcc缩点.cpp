#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;

struct edge{int next,to;}e[2*M];
int head[N],num_edge=1;
void add_edge(int,int);
struct cedge{int next,to;}ce[2*M];
int chead[N],cnum_edge;
void cadd_edge(int,int);

int n,m;
void init();

int dfn[N],low[N],now=0;
bool bridge[2*M];//is_bridge
void tarjan(int,int);//tarjan

int c[N],tot;
void dfs(int);
void draw();//缩点

int main()
{
	init();
	draw();
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
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		add_edge(x,y);
		add_edge(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i,0);
}
void tarjan(int x,int in_edge)
{
	dfn[x]=low[x]=++now;
	for(int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to])
		{
			tarjan(e[i].to,i);
			low[x]=min(low[x],low[e[i].to]);
			if(low[e[i].to]>dfn[x])bridge[i]=bridge[i^1]=1;
		}
		else if(i!=(in_edge^1))low[x]=min(low[x],dfn[e[i].to]);
        /*桥边判定：戳[父]<追溯[子]*/
}
void dfs(int x)//去掉桥边求联通块
{
	c[x]=tot;
	for(int i=head[x];i;i=e[i].next)
		if(!c[e[i].to]&&!bridge[i])
			dfs(e[i].to);
}
void draw()
{
	for(int i=1;i<=n;i++)
		if(!c[i])
		{
			tot++;
			dfs(i);
		}
	for(int i=2;i<=num_edge;i++)
		if(c[e[i^1].to]!=c[e[i].to])
			cadd_edge(c[e[i^1].to],c[e[i].to]);
}