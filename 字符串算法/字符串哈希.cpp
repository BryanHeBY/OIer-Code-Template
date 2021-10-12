#include<bits/stdc++.h>
#define GQD
const int N=2e5,M=5e5+5;
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

#ifdef GQ
    struct edge{int next,to;}e[M*2];
    int num_edge,head[N];
    void add_edge(int from,int to){e[++num_edge]=(edge){head[from],to};head[from]=num_edge;}
    #define EF(x) for(int _iter=head[x],y;y=e[_iter].to,_iter;_iter=e[_iter].next)
#endif

#ifdef GQD
    struct edge{int next,to,d;}e[M*2];
    int num_edge,head[N];
    void add_edge(int from,int to,int d){e[++num_edge]=(edge){head[from],to,d};head[from]=num_edge;}
    #define EF(x) for(int _iter=head[x],y,d;y=e[_iter].to,d=e[_iter].d,_iter;_iter=e[_iter].next)
#endif

}
using namespace n_stl;

const int p=13331;
int ppow[N+5];
char s[N+5];
int l;
int f[N+5];

int get_hash(int *v,int l,int r){
    return f[r]-f[l-1]*ppow[r-l+1];
}

int main(){
    ppow[0]=1;
    F(i,1,N)ppow[i]=ppow[i-1]*p;
    scanf("%s", s+1);
    l=strlen(s+1);
    F(i,1,l)f[i]=f[i-1]*p+s[i];
    //do something
    return 0;
}

