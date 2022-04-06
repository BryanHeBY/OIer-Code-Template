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

int match[N];
bool view[N];

int dfs(int x){
    EF(x,y) {
        if(view[y])continue;
        view[y]=1;
        if(!match[y]||dfs(match[y])){
            match[y]=x;
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
    F(i,1,n){
        F(y,1,m)view[y]=0;
        ans+=dfs(i);
    }
    print(ans);
    return 0;
}