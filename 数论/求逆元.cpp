#include<bits/stdc++.h>
using namespace std;
const int N=100;
typedef long long ll;
ll exgcd(ll,ll,ll&,ll&);
ll inv(ll,ll);
int sta[N],top;
ll stack_inv(ll,ll);

ll qmul(ll,ll,ll);
ll Fermat_inv(ll,ll);

int main()
{
    //do something
    return 0;
}

/*
	x=y1;
	y=x1-(a/b)*y1;
*/

ll exgcd(ll a,ll b,ll &x,ll &y)//扩欧求逆元
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll r=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return r;
}
ll inv(ll a,ll mod)
{
	ll x,y;
	exgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}

ll stack_inv(ll a,ll mod)//栈模拟扩欧求逆元
{
	ll r;
	ll b=mod;
	while(b)
	{
		sta[++top]=a/b;
		r=b,b=a%b,a=r;
	}
	ll x=1,y=0;
	while(top)
	{
		swap(x,y);
		y-=sta[top--]*x;
	}
	return (x%mod+mod)%mod;
}

ll qmul(ll a,ll b,ll mod)//快速乘(防爆long long神器)
{
	ll base=a,ans=0;
	while(b)
	{
		if(b&1)ans=(ans+base)%mod;
		base=(base<<1)%mod;
		b>>=1;
	}
	return ans;
}
ll Fermat_inv(ll a,ll mod)//费马小定理求逆元
{
	ll b=mod-2;
	ll base=a%mod,ans=1;
	while(b)
	{
		if(b&1)ans=(ans*base)%mod;//ans=qmul(ans,base,mod);
		base=(base*base)%mod;//base=qmul(base,base,mod);
		b>>=1;
	}
	return ans;
}