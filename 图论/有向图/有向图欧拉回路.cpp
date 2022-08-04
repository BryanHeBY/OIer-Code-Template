#include<bits/stdc++.h>
//#define GQ
const int N=1e5+5,M=2e5+5;
namespace n_stl{
    using namespace std;
    #define F(i,l,r) for(int i=l;i<=r;++i)
    #define DF(i,r,l) for(int i=r;i>=l;i--)
    typedef long long ll;
    
    
    inline int R(){
        int n=0,f=1;char s;
        while(s=getchar(),!isdigit(s)&&s!='-');
        if(s=='-')f=-1,s=getchar();
        do n=(n<<3)+(n<<1)+(s^48),s=getchar(); while(isdigit(s));
        return n*f;
    } 
    inline ll RL(){
        ll n=0,f=1;char s;
        while(s=getchar(),!isdigit(s)&&s!='-');
        if(s=='-')f=-1,s=getchar();
        do n=(n<<3)+(n<<1)+(s^48),s=getchar(); while(isdigit(s));
        return n*f;
    }
    template<class T>
    void print(T n){
        if(n<0)return putchar('-'),print(-n);
        if(n>=10)print(n/10);
        putchar('0'+n%10);
    }
    template<class T>
    inline void pri(T n,char s){print(n),putchar(s);}
    template<class T>
    inline void pri(T n1,char s1,T n2,char s2){pri(n1,s1),pri(n2,s2);}
    template<class T>
    inline void Swap(T &a, T &b){T tmp=a;a=b;b=tmp;}

#ifdef GQ
    struct edge{int next,to;}e[M*2];
    int num_edge,head[N];
    void add_edge(int from,int to){e[++num_edge]=(edge){head[from],to};head[from]=num_edge;}
    #define EF(x,y) for(int _iter=head[x],y;y=e[_iter].to,_iter;_iter=e[_iter].next)
#endif

#ifdef GQD
    struct edge{int next,to,d;}e[M];
    int num_edge,head[N];
    void add_edge(int from,int to,int d){e[++num_edge]=(edge){head[from],to,d};head[from]=num_edge;}
    #define EF(x,y,ed) for(int _iter=head[x],y,ed;y=e[_iter].to,ed=e[_iter].d,_iter;_iter=e[_iter].next)
#endif

}
using namespace n_stl;

vector<int> G[N];
int id[N], od[N];

int n=R(), m=R();

int startG[N];

int sta[M], top;

void dfs(int x){
    for(; startG[x]<G[x].size();) {
        dfs(G[x][startG[x]++]);
    }
    sta[++top]=x;
}

int main(){
    F(i,1,m){
        int x=R(), y=R();
        G[x].push_back(y);
        od[x]++, id[y]++;
    }
    int begin=-1, end=-1;
    F(i,1,n){
        if(id[i]==od[i])continue;
        if(od[i]==id[i]+1){
            if(begin==-1)begin=i;
            else {printf("No");return 0;}
        } else if(id[i]==od[i]+1){
            if(end==-1)end=i;
            else {printf("No");return 0;}
        } else {printf("No");return 0;}
    }
    F(i,1,n)sort(G[i].begin(), G[i].end());
    if(begin==-1&&end==-1)dfs(1);
    else if(begin!=-1&&end!=-1)dfs(begin);
    else {printf("No");return 0;}
    while(top)pri(sta[top--], ' ');
    return 0;
}