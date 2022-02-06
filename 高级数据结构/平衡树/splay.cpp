#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;

struct tree
{
    int ch[N][2],data[N],fa[N],size[N],cnt[N],now,root;
    void up(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
    void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=x==ch[y][1];
        if(z)ch[z][y==ch[z][1]]=x;fa[x]=z;
        ch[y][k]=ch[x][k^1],fa[ch[x][k^1]]=y;
        ch[x][k^1]=y,fa[y]=x;
        up(y),up(x);
    }
    void splay(int x,int goal)
    {
        while(fa[x]!=goal)
        {
            int y=fa[x],z=fa[y];
            if(z!=goal)
                (x==ch[y][1])^(y==ch[z][1])?rotate(x):rotate(y);
            rotate(x);
        }
        if(!goal)root=x;
    }
    void insert(int key)
    {
        int x=root,ff=0;
        while(x&&data[x]!=key)ff=x,x=ch[x][key>data[x]];
        if(x)cnt[x]++;
        else
        {
            x=++now;
            ch[x][0]=ch[x][1]=0,data[x]=key,size[x]=cnt[x]=1,fa[x]=ff;
            if(ff)ch[ff][key>data[ff]]=x;
        }
        splay(x,0);//splay里面是用splay到根来更新整棵树的 
    }
    void build(){insert(-inf),insert(inf);}
    int find(int key)
    {
        int x=root;
        while(data[x]!=key&&ch[x][key>data[x]])x=ch[x][key>data[x]];
        return x;
    }
    int next(int key,int d)
    {
        splay(find(key),0);
        int x=root;
        if((!d&&data[x]<key)||(d&&data[x]>key))return x;
        x=ch[x][d];
        while(ch[x][d^1])x=ch[x][d^1];
        return x;
    }
    void del(int key)
    {
        int pre=next(key,0),nextn=next(key,1);
        splay(pre,0),splay(nextn,pre);
        int x=ch[nextn][0];
        if(cnt[x]>1)cnt[x]--,splay(x,0);
        else ch[nextn][0]=0,splay(nextn,0);
    }
    int K_th(int rank)
    {
        int x=root;
        while(233)
        {
            if(rank<=size[ch[x][0]])x=ch[x][0];
            else if(rank<=size[ch[x][0]]+cnt[x])return x;
            else rank-=size[ch[x][0]]+cnt[x],x=ch[x][1];
        }
    }
    //附加操作，类似线段树一样建树 
    void build(int l,int r,int ff)
    {
        if(l>r)return;
        int mid=(l+r)>>1;
        ch[mid][0]=ch[mid][1]=data[mid]=0;
        if(ff)ch[ff][mid>ff]=mid;
        cnt[mid]=1,fa[mid]=ff;
        if(l!=r)build(l,mid-1,mid),build(mid+1,r,mid);
        up(mid);
    }
}T;

int main()
{
	
	return 0;
}
