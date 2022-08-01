#include<bits/stdc++.h>
#define lc p<<1
#define rc (p<<1)|1
using namespace std;
const int N=5e5+5;

int n,m,root,mod;
int a[N];

struct edge{int next,to;}e[2*N];
int head[N],num_edge;
void add_edge(int from,int to){e[++num_edge]=(edge){head[from],to},head[from]=num_edge;}

int size[N],fa[N],wson[N],dep[N];
int dfn[N],b[N],now,top[N];
void dfs1(int x,int f)
{
    size[x]=1,wson[x]=0,dep[x]=dep[f]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int y=e[i].to;
        if(y!=f)
        {
            dfs1(y,x);
            size[x]+=size[y],fa[y]=x;
            if(size[y]>size[wson[x]])wson[x]=y;
        }
    }
}
void dfs2(int x,int topf)
{
    dfn[x]=++now,b[now]=a[x],top[x]=topf;
    if(!wson[x])return;
    dfs2(wson[x],topf);
    for(int i=head[x];i;i=e[i].next)
        if(!dfn[e[i].to])dfs2(e[i].to,e[i].to);
}

int lx[N],rx[N];
long long sum[N],tag[N];
void build(int p,int l,int r)
{
	lx[p]=l,rx[p]=r,tag[p]=0;
	if(l==r){sum[p]=b[l]%mod;return;}
	int mid=(l+r)>>1;
	build(lc,l,mid),build(rc,mid+1,r);
	sum[p]=(sum[lc]+sum[rc])%mod;
}
void down(int p)
{
	if(!tag[p])return;
	sum[lc]=(sum[lc]+tag[p]*(rx[lc]-lx[lc]+1))%mod,sum[rc]=(sum[rc]+tag[p]*(rx[rc]-lx[rc]+1));
	tag[lc]=(tag[lc]+tag[p]),tag[rc]=(tag[rc]+tag[p]),tag[p]=0;
}
void add(int p,int l,int r,long long key)
{
    if(l<=lx[p]&&rx[p]<=r){sum[p]=(sum[p]+key*(rx[p]-lx[p]+1)),tag[p]=(tag[p]+key);return;}
    down(p);
    int mid=(lx[p]+rx[p])>>1;
    if(l<=mid)add(lc,l,r,key);if(r>mid)add(rc,l,r,key);
    sum[p]=(sum[lc]+sum[rc])%mod;
}
long long ask(int p,int l,int r)
{
    if(l<=lx[p]&&rx[p]<=r)return sum[p];
    down(p);
    long long ans=0;
    int mid=(lx[p]+rx[p])>>1;
    if(l<=mid)ans=(ans+ask(lc,l,r))%mod;if(r>mid)ans=(ans+ask(rc,l,r))%mod;
    return ans;
}

void add_l(int x,int y,long long key)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		add(1,dfn[top[x]],dfn[x],key);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	add(1,dfn[x],dfn[y],key);
}
int ask_l(int x,int y)
{
	long long ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=(ans+ask(1,dfn[top[x]],dfn[x]))%mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=(ans+ask(1,dfn[x],dfn[y]))%mod;
	return ans;
}
void add_t(int x,int key){add(1,dfn[x],dfn[x]+size[x]-1,key);}
int ask_t(int x){return ask(1,dfn[x],dfn[x]+size[x]-1);}

int main()
{
	scanf("%d%d%d%d",&n,&m,&root,&mod);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=(a[i]+mod)%mod;
	int op,x,y,k;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs1(root,0),dfs2(root,root);
	
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		switch(op)
		{
			case 1:scanf("%d%d%d",&x,&y,&k),add_l(x,y,k);break;
			case 2:scanf("%d%d",&x,&y),printf("%d\n",ask_l(x,y));break;
			case 3:scanf("%d%d",&x,&k),add_t(x,k);break;
			case 4:scanf("%d",&x),printf("%d\n",ask_t(x));break;
		}
	}
	return 0;
}

// 洛谷P3384