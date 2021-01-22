#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;
int n,m;
struct ge{int x,y,d;}te[N];
bool cmp(ge a,ge b){return a.d<b.d;}
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void kruskal()
{
    for(int i=1;i<=n;i++)f[i]=i;
    sort(te+1,te+m+1,cmp);
    int con=0;
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int r1=find(te[i].x),r2=find(te[i].y);
        if(r1!=r2)
        {
            f[r1]=r2;
            con++;
            ans+=te[i].d;
        }
        if(con==n-1)break;
    }
    if(con!=n-1)cout<<"orz";
    else cout<<ans;
}

int main()
{
    cin>>n>>m;
    int x,y,d;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>d;
        te[i]=(ge){x,y,d};
    }
    kruskal();
    return 0;
}