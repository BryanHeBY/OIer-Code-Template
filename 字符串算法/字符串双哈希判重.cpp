#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll p[2]={131,13331},mod[2]={1e5+3,1e8+7};
const int M=1e5+3,N=1e4+5;
int head[M],nextn[N],val[N];
char s[10005];
void add(char*,int);
ll get_hash(char*,int);
int cnt=0;
int main()
{
    
    return 0;
}

ll get_hash(char* t,int key)
{
    ll ans=0;
    int l=strlen(t);
    for(int i=0;i<l;i++)
        ans=(ans*p[key]%mod[key]+t[i])%mod[key];
    return ans;
}
void add(char* t,int num)
{
    int h1=get_hash(t,0),h2=get_hash(t,1);
    for(int i=head[h1];i;i=nextn[i])
        if(val[i]==h2)return;
    nextn[num]=head[h1],val[num]=h2;
    head[h1]=num;
    cnt++;
}

//[洛谷例题P3370](https://www.luogu.org/problemnew/show/P3370)