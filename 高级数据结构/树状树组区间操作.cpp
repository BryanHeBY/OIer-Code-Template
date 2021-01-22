#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct BT
{
	int n;
	ll c1[N],c2[N];
	void add(int pos,ll val){for(int i=pos;i<=n;i+=i&-i)c1[i]+=val,c2[i]+=val*(pos-1);}
	ll ask(int pos)
	{
		ll ans=0;
		for(int i=pos;i;i-=i&-i)ans+=c1[i]*pos-c2[i];
		return ans;
	}
}T;

int main()
{
    
    return 0;
}
