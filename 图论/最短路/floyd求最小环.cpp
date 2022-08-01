#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
void init();
int a[N][N],dis[N][N];
int floyd_circle();

int main()
{
    init();
    cout<<floyd_circle();
    return 0;
}

void init()
{
     memset(a,127/3,sizeof a);
     cin>>n>>m;
     int x,y,d;
     for(int i=1;i<=m;i++)
     {
     	cin>>x>>y>>d;
     	a[x][y]=a[y][x]=min(a[x][y],d);
     }
     memcpy(dis,a,sizeof a);
} 
int floyd_circle()
{
     int ans=100000008;
     for(int k=1;k<=n;k++)
     {
         for(int i=1;i<k;i++)
         for(int j=i+1;j<k;j++)
             ans=min(ans,dis[i][j]+a[i][k]+a[k][j]);
         for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
             dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
     }
     return ans;
}
