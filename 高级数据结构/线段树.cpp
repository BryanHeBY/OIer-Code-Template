#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
struct segmenttree{
    int l,r;
    ll sum,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
    #define lc p<<1
    #define rc (p<<1)|1
}tree[4*N];
int a[N],n,m;
void build(int,int,int);
void spread(int);
void change(int,int,int,int);
ll ask(int,int,int);

int main()
{
	
    return 0;
}

void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l==r){sum(p)=a[l];return;}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	sum(p)=sum(lc)+sum(rc);
}
void spread(int p)
{
	if(add(p))
	{
		sum(lc)+=add(p)*(r(lc)-l(lc)+1);
		sum(rc)+=add(p)*(r(rc)-l(rc)+1);
		add(lc)+=add(p);
		add(rc)+=add(p);
		add(p)=0;
	}
}
void change(int p,int l,int r,int d)
{
	if(l<=l(p)&&r(p)<=r)
	{
		sum(p)+=1LL*d*(r(p)-l(p)+1);
		add(p)+=d;
		return;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid)change(lc,l,r,d);
	if(r>mid)change(rc,l,r,d);
	sum(p)=sum(lc)+sum(rc);
}
ll ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)return sum(p);
	ll ans=0;
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid)ans+=ask(lc,l,r);
	if(r>mid)ans+=ask(rc,l,r);
	return ans;
}

/*
洛谷例题
[P3372](https://www.luogu.org/problemnew/show/P3372)
[P3373](https://www.luogu.org/problemnew/show/P3373)
*/