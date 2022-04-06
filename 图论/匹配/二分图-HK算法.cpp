#include<bits/stdc++.h>
#define GQ
const int N=5e2+5,M=5e4+5;
namespace n_stl{
    using namespace std;
    #define fre(A) freopen(A".in","r",stdin);freopen(A".out","w",stdout);
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
    inline void pri(T n1,char s1,T n2,char s2){pri(n1,s1), pri(n2,s2);}

#ifdef GQ
    struct edge{int next,to;}e[M*2];
    int num_edge,head[N];
    void add_edge(int from,int to){e[++num_edge]=(edge){head[from],to};head[from]=num_edge;}
    #define EF(x,y) for(int _iter=head[x],y;y=e[_iter].to,_iter;_iter=e[_iter].next)
#endif

#ifdef GQD
    struct edge{int next,to,d;}e[M*2];
    int num_edge,head[N];
    void add_edge(int from,int to,int d){e[++num_edge]=(edge){head[from],to,d};head[from]=num_edge;}
    #define EF(x,y,d) for(int _iter=head[x],y,d;y=e[_iter].to,d=e[_iter].d,_iter;_iter=e[_iter].next)
#endif

}
using namespace n_stl;

int n=R(), m=R(), ne=R();
int dx[N], dy[N], mxy[N], myx[N];
int dis;
bool view[N];
const int inf = 1e8;

bool bfs(){
    dis=inf;
    queue<int> q;
    F(x,1,n)if(!mxy[x])dx[x]=0,q.push(x);else dx[x]=-1;
    F(y,1,m)dy[y]=-1;
    while(!q.empty()) {
        int x=q.front();q.pop();
        if(dx[x]>dis)break;
        EF(x,y) {
            if(dy[y]!=-1)continue;
            dy[y]=dx[x]+1;
            if(!myx[y])dis=dy[y];
            else dx[myx[y]]=dy[y]+1, q.push(myx[y]);
        }
    }
    return dis!=inf;
}

int dfs(int x){
    EF(x,y){
        if(view[y]||dy[y]!=dx[x]+1)continue;
        view[y]=1;
        if(!myx[y]||dfs(myx[y])){
            myx[y]=x, mxy[x]=y;
            return 1;
        }
    }
    return 0;
}

int main(){
    F(i,1,ne){
        int x=R(), y=R();
        add_edge(x, y);
    }
    int ans=0;
    while(bfs()){
        F(y,1,m)view[y]=0;
        F(x,1,n)if(!mxy[x])ans+=dfs(x);
    }
    print(ans);
    return 0;
}
