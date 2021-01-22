#include<bits/stdc++.h>
const int N=5e6+5;
const double pi=acos(-1);
int bt[N];
inline int read();
struct z
{
    double x,y;
    z(double xx=0,double yy=0){x=xx,y=yy;}
}w[N],f[2][N],t[N];
z operator + (z a,z b){return z(a.x+b.x,a.y+b.y);}
z operator - (z a,z b){return z(a.x-b.x,a.y-b.y);}
z operator * (z a,z b){return z(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
z judge(z a,bool type){return type?a:z(a.x,-a.y);}
int n,m,limit,md;
void init()
{
    n=read(),m=read();
    for(int i=0;i<=n;i++)f[0][i].x=read();
    for(int i=0;i<=m;i++)f[1][i].x=read();
    limit=1;
    while(limit<=n+m)limit<<=1,md++;
    w[0]=z(1),w[1]=z(cos(2*pi/limit),sin(2*pi/limit));
    for(int i=2;i<limit;i++)w[i]=w[i-1]*w[1];
    for(int i=1;i<limit;i++)
        bt[i]=(bt[i>>1]>>1)|((i&1)?(1<<(md-1)):0);
}

void dft(z *a,bool type)
{
    for(int i=0;i<limit;i++)t[i]=a[bt[i]];
    for(int i=md-1;i>=0;i--)
        for(int j=0;j<(1<<i);j++)
            for(int k=0;k<(limit>>(i+1));k++)
    {
        int t1=j*(limit>>i)+k,t2=t1+(limit>>(i+1));
        z z1=t[t1],z2=t[t2]*judge(w[k<<i],type);
        t[t1]=z1+z2,t[t2]=z1-z2;
    }
    for(int i=0;i<limit;i++)a[i]=t[i];
}

int main()
{
    init();
    dft(f[0],1),dft(f[1],1);
    for(int i=0;i<=limit;i++)f[0][i]=f[0][i]*f[1][i];
    dft(f[0],0);
    for(int i=0;i<=n+m;i++)printf("%d ",(int)(f[0][i].x/limit+0.5));
    return 0;
}

inline int read()
{
    int n=0,f=1;
    char s;
    while(((s=getchar())<'0'||s>'9')&&s!='-');
    if(s=='-')f=-1,s=getchar();
    do{n=(n<<1)+(n<<3)+(s^48);}while((s=getchar())>='0'&&s<='9');
    return n*f;
}