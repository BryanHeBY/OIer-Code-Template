#include<bits/stdc++.h>
//#define GQD
const int N=2e3+5,M=50;
const int inf=1e9;
using namespace std;
#define F(i,l,r) for(int i=l;i<=r;++i)
#define DF(i,r,l) for(int i=r;i>=l;i--)
typedef long long ll;
ll num[N], base[M+5];
int n;

void getBase() {
    memset(base,0,sizeof base);
    F(i,1,n) DF(j,M,0) if(num[i]&(1ll<<j)){
        if(!base[j]) {base[j]=num[i]; break;}
        else  num[i]^=base[j];
    }
}

int main() {
    scanf("%d", &n);
    F(i,1,n) scanf("%lld", &num[i]);
    getBase();
    ll ans=0;
    DF(i,M,0) if((ans^base[i])>ans)ans^=base[i];
    printf("%lld\n", ans);
    return 0;
}