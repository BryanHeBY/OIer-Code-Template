#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;

struct edge{int next,to,d;}e[M];
int head[N],num_edge;
void add_edge(int,int,int);

int n,m,maxd;
int d[N],dis[N];
int f[N][20];
void init();void solve();

int main()
{
	init();
	solve();
	return 0;
}

void add_edge(int from,int to,int d)
{
	e[++num_edge]=(edge){head[from],to,d};
	head[from]=num_edge;
}
void init()
{
	cin>>n;
	maxd=log(n)/log(2)+1;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,d;
		cin>>x>>y>>d;
		add_edge(x,y,d);
		add_edge(y,x,d);
	}
	//bfs
	queue<int> q;
	d[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(int i=head[t];i;i=e[i].next)
		if(!d[e[i].to])
		{
			d[e[i].to]=d[t]+1,dis[e[i].to]=dis[t]+e[i].d;
                  //更新到根节点距离
			f[e[i].to][0]=t;//确定父节点
			for(int j=1;j<=maxd;j++)
				f[e[i].to][j]=f[f[e[i].to][j-1]][j-1];
                //上爬
			q.push(e[i].to);
		}
	}
}
int lca(int x,int y)
{
	if(d[x]>d[y])swap(x,y);//x浅y深
	for(int i=maxd;i>=0;i--)
		if(d[f[y][i]]>=d[x])y=f[y][i];//y上爬至等深
	if(x==y)return x;
	for(int i=maxd;i>=0;i--)
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
        //若没找到任意公共祖先继续找
	return f[x][0];
}
void solve()
{
	cin>>m;
	int x,y,l;
	while(m--)
	{
		cin>>x>>y;
		l=lca(x,y);
		cout<<l<<" "<<dis[x]+dis[y]-2*dis[l]<<endl;
	}
}
