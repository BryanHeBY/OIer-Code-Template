#include<bits/stdc++.h>
const int N=5e5+5;
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
struct SA
{
    int sa[N],wa[N],wb[N],buc[N],*rank;
    int n,z;
    char ch[N];
    bool cmp(int *t,int a,int b,int j){return t[a]==t[b]&&t[a+j]==t[b+j];}
    void msort(int *x,int *y)
    {
        memset(buc,0,z<<2);
        F(i,0,n-1)buc[x[y[i]]]++;
        F(i,1,z-1)buc[i]+=buc[i-1];
        DF(i,n-1,0)sa[--buc[x[y[i]]]]=y[i];
        
    }
    void GA()
    {
        int *x=wa,*y=wb,i,j,p;
        z=278;
        RF(i,0,n-1)x[i]=ch[i],y[i]=i;
        msort(x,y);
        for(p=1,j=1;p!=n;j<<=1,z=p)
        {
            p=0;
            RF(i,n-j,n-1)y[p++]=i;
            RF(i,0,n-1)if(sa[i]>=j)y[p++]=sa[i]-j;
            msort(x,y);
            swap(x,y),p=1,x[sa[0]]=0;
            RF(i,1,n-1)x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
        }
        rank=x;
    }
    int height[N];
    void GH()
    {
        int k=0,i;
        height[1]=0;
        for(i=0;i<n-1;height[rank[i++]]=k)
            for(k?k--:0;ch[i+k]==ch[sa[rank[i]-1]+k];k++);
    }
}T;

int main()
{
    scanf("%s",T.ch);
    T.n=strlen(T.ch);
    T.GA();T.GH();
    
    return 0;
}