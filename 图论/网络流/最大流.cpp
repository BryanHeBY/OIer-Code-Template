#include<bits/stdc++.h>
const int N=5050,inf=1e8;
namespace n_stl{
    using namespace std;
    #define F(i,l,r) for(register int i=l;i<=r;++i)
    #define DF(i,r,l) for(register int i=r;i>=l;--i)
    #define RF(i,l,r) for(i=l;i<=r;++i)
    typedef long long ll;
    inline int R(){
        int n=0,f=1;char s;
        while(s=getchar(),(s<'0'||s>'9')&&s!='-');
        if(s=='-')f=-1,s=getchar();
        do n=(n<<1)+(n<<3)+(s^48),s=getchar();while(s>='0'&&s<='9');
        return f*n; 
    }
    inline ll RL(){
        ll n=0,f=1;char s;
        while(s=getchar(),(s<'0'||s>'9')&&s!='-');
        if(s=='-')f=-1,s=getchar();
        do n=(n<<1)+(n<<3)+(s^48),s=getchar();while(s>='0'&&s<='9');
        return f*n; 
    }
    void print(int n){
        if(n<0)return putchar('-'),print(-n);
        if(n>=10)print(n/10);
        putchar(n%10+'0');
    } 
    inline void pri(int n,char s){print(n),putchar(s);}
    void print(ll n){
        if(n<0)return putchar('-'),print(-n);
        if(n>=10)print(n/10);
        putchar(n%10+'0');
    } 
    inline void pri(ll n,char s){print(n),putchar(s);}
} 
using namespace n_stl;
struct edge{int next,to,d;}e[N];
int head[N*2],num_edge=1;
void add_edge(int from,int to,int d){
    e[++num_edge]=(edge){head[from],to,d},head[from]=num_edge;
    e[++num_edge]=(edge){head[to],from,0},head[to]=num_edge;
}
int n,m,s,t;
int d[N];queue<int> q;
bool bfs()
{
    memset(d,0,sizeof d);
    while(!q.empty())q.pop();
    d[s]=1;q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x],y;y=e[i].to,i;i=e[i].next)
            if(e[i].d&&!d[y])
        {
            d[y]=d[x]+1;q.push(y);
            if(y==t)return 1;
        }
    }
    return 0;
}
int dinic(int x,int flow)
{
    if(x==t)return flow;
    int rest=flow,k;
    for(int i=head[x],y;y=e[i].to,i;i=e[i].next)
        if(e[i].d&&d[y]==d[x]+1) 
    {
        k=dinic(y,min(rest,e[i].d));
        if(!k)d[y]=0;
        e[i].d-=k,e[i^1].d+=k;
        rest-=k;
    } 
    return flow-rest;
}


int main()
{
    ll sum=0,max_flow=0,flow;
    while(bfs())while(flow=dinic(s,inf))max_flow+=flow;
    
    return 0;	
}