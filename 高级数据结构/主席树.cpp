#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];

struct psmt
{
    int data[20*N],lc[20*N],rc[20*N],rt[N],cnt;
    int build(int l,int r)
    {
        int now=++cnt,mid=(l+r)>>1;
        if(l==r)data[now]=a[l];
        else lc[now]=build(l,mid),rc[now]=build(mid+1,r);
        return now;
    }
    int modify(int pre,int l,int r,int pos,int val)
    {
        int now=++cnt,mid=(l+r)>>1;
        data[now]=data[pre],lc[now]=lc[pre],rc[now]=rc[pre];
        if(l==r)data[now]=val;
        else 
        {
            if(pos<=mid)lc[now]=modify(lc[pre],l,mid,pos,val);
            else rc[now]=modify(rc[pre],mid+1,r,pos,val);
        }
        return now;
    }
    int query(int now,int l,int r,int pos)
    {
        if(l==r)return data[now];
        int mid=(l+r)>>1;
        return pos<=mid?query(lc[now],l,mid,pos):query(rc[now],mid+1,r,pos);
    }
}T;

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    T.rt[0]=T.build(1,n);
    int x,op,y,z;
    
    return 0; 
}
