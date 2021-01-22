#include<bits/stdc++.h>
const int N=2e6+5;
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
int ans;
struct SAM
{
    int ch[N][26],len[N],fa[N],siz[N],last,cnt;
    void init(){last=cnt=1,fa[1]=0;}
    void ins(int s)
    {
        int cur=++cnt,p=last;
        len[cur]=len[last]+1,siz[cur]=1;
        for(;p&&!ch[p][s];p=fa[p])ch[p][s]=cur;
        if(!p)fa[cur]=1;
        else
        {
            int q=ch[p][s];
            if(len[q]==len[p]+1)fa[cur]=q;
            else
            {
                int clone=++cnt;
                memcpy(ch[clone],ch[q],26<<2);len[clone]=len[p]+1,fa[clone]=fa[q];
                for(;p&&ch[p][s]==q;p=fa[p])ch[p][s]=clone;
                fa[cur]=fa[q]=clone;
            }
        }
        last=cur;
    }
    int buc[N],id[N];
    void bsort()
    {
        F(i,1,cnt)buc[len[i]]++;
        F(i,1,cnt)buc[i]+=buc[i-1];
        DF(i,cnt,1)id[buc[len[i]]--]=i;
    }
}T;
char s[N];int l;

int main()
{
    scanf("%s",s+1);l=strlen(s+1);
    T.init();
    F(i,1,l)T.ins(s[i]-'a');
    T.bsort();
    return 0;	
}