#include<bits/stdc++.h>
const int N=3e5+5;
namespace n_stl{
    using namespace std;
    #define F(i,l,r) for(register int i=l;i<=r;++i)
    #define DF(i,r,l) for(register int i=r;i>=l;--i)
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
ll ans=0;
struct PAM
{
    int ch[N][26],fa[N],len[N],scnt[N],pcnt[N],str[N];
    int last,n,tot;
    void init()
    {
        len[tot++]=0,len[tot++]=-1;
        last=0,n=0,str[0]=-1,fa[0]=1;
    }
    int find(int p)
    {
        while(str[n-1-len[p]]!=str[n])p=fa[p];
        return p;
    }
    void ins(int s)
    {
        str[++n]=s;
        int cur=find(last);
        if(!ch[cur][s])
        {
            int now=tot++;
            len[now]=len[cur]+2,fa[now]=ch[find(fa[cur])][s];
            ch[cur][s]=now;
            pcnt[now]=pcnt[fa[now]]+1;
        }
        last=ch[cur][s],scnt[last]++;
    }
    void count()
    {
        DF(i,tot-1,0)scnt[fa[i]]+=scnt[i];
    }
}T;
char s[N];
int l;
int main()
{
    scanf("%s",s+1);l=strlen(s+1);
    T.init();
    F(i,1,l)T.ins(s[i]-'a');
    T.count();
    
    return 0;
}