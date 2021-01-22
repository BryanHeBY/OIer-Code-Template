#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;
struct edge{int next,to,d;}e[N];
int num_edge,head[N];
void add_edge(int from,int to,int d)
{
	e[++num_edge]=(edge){head[from],to,d};
	head[from]=num_edge;
}
int dis[N];
int n,m,f,t;
void init()
{
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[f]=0;
}

void dijkstra()
{
	for(int i=1;i<=n;i++)
	{
		int k=0,d=inf;
		for(int i=1;i<=n;i++)
			if(dis[i]<d)k=i,d=dis[i];
		if(!k)break;
		for(int i=head[k];i;i=e[i].next)
			dis[e[i].to]=min(dis[e[i].to],dis[k]+e[i].d);
	}
}

struct node
{
	int v,d;
	bool operator<(const node& a)const{return d>a.d;};
};
void heap_dijkstra()
{
	priority_queue<node> pq;
	pq.push((node){f,dis[f]});
	while(!pq.empty())
	{
		node temp=pq.top();pq.pop();
		if(dis[temp.v]!=temp.d)continue;
		for(int i=head[temp.v];i;i=e[i].next)
			if(dis[e[i].to]>dis[temp.v]+e[i].d)
		{
			dis[e[i].to]=dis[temp.v]+e[i].d;
			pq.push((node){e[i].to,dis[e[i].to]});
		}
	}
}

void bellman_ford()
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[e[2*j-1].to]=min(dis[e[2*j-1].to],dis[e[2*j].to]+e[2*j].d);
			dis[e[2*j].to]=min(dis[e[2*j].to],dis[e[2*j-1].to]+e[2*j].d);
		}
	}
}

bool inq[N];
void spfa()
{
	queue<int> q;
	q.push(f);inq[f]=0;
	while(!q.empty())
	{
		int temp=q.front();q.pop();
		inq[temp]=0;
		for(int i=head[temp];i;i=e[i].next)
		if(dis[e[i].to]>dis[temp]+e[i].d)
		{
			dis[e[i].to]=dis[temp]+e[i].d;
			if(!inq[e[i].to])q.push(e[i].to),inq[e[i].to]=1;
		}
	}
}

int dis2[1000][1000];
void floyed()
{
	memset(dis2,127/3,sizeof(dis2));
	for(int i=1;i<=m;i++)
		dis2[e[2*i-1].to][e[2*i].to]=dis2[e[2*i].to][e[2*i-1].to]=e[i].d;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
	cout<<dis2[f][t];
}

int main()
{
	cin>>n>>m>>f>>t;
	int x,y,d;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>d;
		add_edge(x,y,d);
		add_edge(y,x,d);
	}
	init();
	return 0;
}
