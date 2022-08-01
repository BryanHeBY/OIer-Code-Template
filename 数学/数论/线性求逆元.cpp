#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=20181030;
ll inv[P];
void get_inv(ll);

int main()
{
    ll p;
    cin>>p;
    get_inv(p);
    return 0;
}

void get_inv(ll mod)
{
	inv[1]=1;
	for(int i=2;i<mod;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}

//[例题洛谷p3811](https://www.luogu.org/problemnew/show/P3811)