#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;
int n,m;
struct cedge{int next,to,d;}ce[N];
int cnum_edge,chead[N];
void cadd_edge(int from,int to,int d)
{
    ce[++cnum_edge]=(cedge){chead[from],to,d};
    chead[from]=cnum_edge;
}
int p[N];
bool view[N];
struct node
{
    int v,d;
    bool operator<(const node& a)const{return d>a.d;}
};
long long ans=0;
void prim()
{
    memset(p,127/3,sizeof(p));
    p[1]=0;
    priority_queue<node> pq;
    pq.push((node){1,0});
    int con=0;
    while(!pq.empty()&&con!=n)
    {
        node t=pq.top();pq.pop();
        if(p[t.v]!=t.d||view[t.v])continue;
        view[t.v]=1,con++;
        ans+=t.d;
        for(int i=chead[t.v];i;i=ce[i].next)
        if(!view[ce[i].to]&&ce[i].d<p[ce[i].to])
        {
            p[ce[i].to]=ce[i].d;
            pq.push((node){ce[i].to,p[ce[i].to]});
        }
    }
    if(con!=n)cout<<"orz";
    else cout<<ans;
}
int main()
{
    cin>>n>>m;
    int x,y,d;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>d;
        cadd_edge(x,y,d);
        cadd_edge(y,x,d);
    }
    prim();
    return 0;
}