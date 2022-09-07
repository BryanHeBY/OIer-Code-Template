#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+5,mod=1004535809;
int read();
char s[N];
ll f[2][N],w[N],t[N];
ll qpow(ll,ll);
int n,m,limit,md;
int bt[N];
void init()
{
    n=read(),m=read();
    for(int i=0;i<=n;i++)f[0][i]=read();
    for(int i=0;i<=m;i++)f[1][i]=read();
    limit=1,md=0;
    while(limit<=n+m)limit<<=1,md++;
    w[0]=1,w[1]=qpow(3,(mod-1)/limit);
    for(int i=2;i<=limit;i++)w[i]=w[i-1]*w[1]%mod;
    for(int i=1;i<limit;i++)
    	bt[i]=(bt[i>>1]>>1)|((i&1)?(1<<(md-1)):0);
}
void dft(ll *a,bool type)
{
    for(int i=0;i<limit;i++)t[i]=a[bt[i]];
    for(int i=md-1;i>=0;i--)
    	for(int j=0;j<(1<<i);j++)
    		for(int k=0;k<(limit>>(i+1));k++)
    {
    	int t1=j*(limit>>i)+k,t2=t1+(limit>>(i+1));
    	ll w1=t[t1],w2=t[t2]*(type?w[k<<i]:w[limit-(k<<i)])%mod;
    	t[t1]=w1+w2>mod?w1+w2-mod:w1+w2,t[t2]=w1-w2<0?w1-w2+mod:w1-w2;
    }
    for(int i=0;i<limit;i++)a[i]=t[i];
    if(!type)
    {
        ll inv=qpow(limit,mod-2);
        for(int i=0;i<limit;i++)a[i]=a[i]*inv%mod;
    }
}

int main()
{
    init();
    dft(f[0],1),dft(f[1],1);
    for(int i=0;i<limit;i++)f[0][i]=f[0][i]*f[1][i]%mod;
    dft(f[0],0);
    for(int i=0;i<=n+m;i++)printf("%lld ",f[0][i]);
    return 0;
}

ll qpow(ll base,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}
inline int read()
{
    int n=0,f=1;
    char s;
    while(((s=getchar())<'0'||s>'9')&&s!='-');
    if(s=='-')f=-1,s=getchar();
    do{n=(n<<1)+(n<<3)+(s^48);}while((s=getchar())>='0'&&s<='9');
    return n*f;
}