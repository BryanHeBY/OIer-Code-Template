#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l;i<=r;++i)
#define DF(i,r,l) for(int i=r;i>=l;--i)
typedef long long ll;
typedef long double ld;
using namespace std;
const int N=2e6+5;
const ll mod=998244353;

ll qpow(ll a,ll n){
    ll ans=1;
    for(;n;(a*=a)%=mod,n>>=1)if(n&1)(ans*=a)%=mod;
    return ans;
}
ll inv(ll a){return qpow(a,mod-2);}

int bt[N];
ll w[N],t[N];
void init(int limit, int md) {
    w[0]=1,w[1]=qpow(3,(mod-1)/limit);
    F(i,2,limit)w[i]=w[i-1]*w[1]%mod;
    F(i,1,limit-1)bt[i]=(bt[i>>1]>>1)|((i&1)?(1<<(md-1)):0);
}
void dft(vector<ll> &a,int limit,int md,bool type){
    F(i,0,limit-1)t[i]=a[bt[i]];
    DF(i,md-1,0)F(j,0,(1<<i)-1)F(k,0,(limit>>(i+1))-1){
        int t1=j*(limit>>i)+k,t2=t1+(limit>>(i+1));
        ll s1=t[t1],s2=t[t2]*(type?w[k<<i]:w[limit-(k<<i)])%mod,w1=s1+s2,w2=s1-s2;
        t[t1]=w1>mod?w1-mod:w1,t[t2]=w2<0?w2+mod:w2;
    }
    F(i,0,limit-1)a[i]=t[i];
    if(!type){
        ll inv_limit=inv(limit);
        F(i,0,limit-1)a[i]=a[i]*inv_limit%mod;
    }
}

struct P{
    int n;
    vector<ll> f;
    P(int n):n(n) {f.resize(n+1);}
    P(int n, const P &b):P(n){
        F(i,0,min(b.n,n))f[i]=b.f[i];
        F(i,b.n+1,n)f[i]=0;
    }
    void reset(int newn){
        int pre=n;
        n=newn;
        f.resize(newn+1);
        if(pre<newn)F(i,pre+1,newn)f[i]=0;
    }

    void print(){
        F(i,0,n)cout<<f[i]<<" ";
        cout<<endl;
    }

    ll &operator[](int i) {return f[i];}
    P operator *(P &b) {
        int limit=1,md=0;
        while(limit<=n+b.n)limit<<=1,md++;
        init(limit,md);
        P f1(limit-1,*this),f2(limit-1,b);
        dft(f1.f,limit,md,1),dft(f2.f,limit,md,1);
        F(i,0,limit-1)f1[i]=(f1[i]*f2[i])%mod;
        dft(f1.f,limit,md,0);
        f1.reset(n+b.n);
        return f1;
    }
};

int main(){
    
    return 0;
}
