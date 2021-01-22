#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;

struct edge{int next,to,d;}e[M];
int head[N],num_edge;
void add_edge(int,int,int);

int n;
void init();

int dp[N],ans;
bool view[N];
void dp_dfs(int);//dp法

void di_solve();
int root,max_long;
int next[N];
bool second=0;
void di_dfs(int,int);//两次dfs法

int main()
{
	init();
	dp_dfs(1);
	cout<<ans<<endl;
	di_solve();
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
	int x,y,d;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y>>d;
		add_edge(x,y,d);
		add_edge(y,x,d);
	}
}
void dp_dfs(int x)
{
	view[x]=1;
	for(int i=head[x];i;i=e[i].next)
	if(!view[e[i].to])
	{
		dp_dfs(e[i].to);
		ans=max(ans,dp[x]+dp[e[i].to]+e[i].d);
		dp[x]=max(dp[x],dp[e[i].to]+e[i].d);
	}
}

void di_solve()
{
	memset(view,0,sizeof(view));
	max_long=0;
	di_dfs(1,0);
	
	memset(view,0,sizeof(view));
	max_long=0,second=1;
	di_dfs(root,0);
	cout<<ans<<endl;
	
	int now=root;
	while(now)
	{
		cout<<now<<" ";
		now=next[now];
	}
}
void di_dfs(int x,int sum_long)
{
	view[x]=1;
	if(sum_long>max_long)
	{
		max_long=sum_long;
		root=x;
	}
	for(int i=head[x];i;i=e[i].next)
	if(!view[e[i].to])
		{
			if(second)next[e[i].to]=x;
			di_dfs(e[i].to,sum_long+e[i].d);
		}
}
