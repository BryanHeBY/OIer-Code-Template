#include<bits/stdc++.h>
//#define GQD
const int N=1e5+5,M=2e6+5;
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
char pat[N], s[N];
int lpat, ls;
int nextn[N], f[N];

void get_nextn(){
    int j=0;
    F(i,2,lpat){
        while(j&&pat[j+1]!=pat[i])j=nextn[j];
        if(pat[j+1]==pat[i])j++;
        nextn[i]=j;
    }
}

void get_f(){
    int j=0;
    F(i,1,ls){
        while(j&&pat[j+1]!=s[i])j=nextn[j];
        if(pat[j+1]==s[i])j++;
        f[i]=j;
    }
}

int main(){
    scanf("%s%s", pat+1, s+1);
    lpat=strlen(pat+1), ls=strlen(s+1);
    get_nextn();
    get_f();

    return 0;
}

