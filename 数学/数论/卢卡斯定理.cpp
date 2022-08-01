#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;

ll mod,fac[N],inv[N];

void init_lucas();
ll lucas(ll,ll);


int main()
{
	
	return 0;
}

void init_lucas()
{
	fac[0]=fac[1]=1;
	inv[1]=1;
	for(int i=2;i<mod;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
}
ll lucas(ll n,ll m)
{
	if(m>n)return 0;
	if(m<mod&&n<mod)return fac[n]*inv[fac[m]*fac[n-m]%mod]%mod;
	return lucas(n/mod,m/mod)*lucas(n%mod,m%mod)%mod;
}

//[洛谷例题P3807](https://www.luogu.org/problemnew/show/P3807)