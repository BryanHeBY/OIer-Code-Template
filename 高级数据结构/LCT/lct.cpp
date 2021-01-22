#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;

struct LCT
{
    int data[N],ch[N][2],fa[N],sum[N];bool tag[N];
    bool nroot(int x){return fa[x]&&ch[fa[x]][x==ch[fa[x]][1]]==x;}
    void pushr(int x){swap(ch[x][0],ch[x][1]),tag[x]^=1;}
    void up(int x){sum[x]=sum[ch[x][0]]^sum[ch[x][1]]^data[x];}
    void down(int x)
    {
        if(tag[x])
        {
            if(ch[x][0])pushr(ch[x][0]);
            if(ch[x][1])pushr(ch[x][1]);
            tag[x]=0;
        }
    }
    void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][k^1];
        if(nroot(y))ch[z][y==ch[z][1]]=x;fa[x]=z;//一定要在前面
        ch[y][k]=w;if(w)fa[w]=y;
        ch[x][k^1]=y,fa[y]=x;
        up(y),up(x);
    }
    void up_down(int x)
    {
        if(nroot(x))up_down(fa[x]);
        down(x);
    }
    void splay(int x)
    {
        up_down(x);
        while(nroot(x))
        {
            int y=fa[x],z=fa[y];
            if(nroot(y))
                rotate((x==ch[y][0])^(y==ch[z][0])?x:y);
            rotate(x);
        }
    }
    void splay_next(int x)
    {
        up_down(x);
        while(nroot(fa[x]))
        {
            int y=fa[x],z=fa[y];
            if(nroot(z))
                rotate((x==ch[y][0])^(y==ch[z][0])?x:y);
            rotate(x);
        }
    }
    void access(int x)
    {
    	for(int y=0;x;x=fa[y=x])
        	splay(x),ch[x][1]=y,up(x);
    }
    void makeroot(int x){access(x),splay(x),pushr(x);}
    bool linked(int x,int y)
    {
        makeroot(x),access(y);
    	splay(x),splay_next(y);
    	return fa[y]==x;
    }
    void Link(int x,int y){if(!linked(x,y))fa[x]=y;}//顺序不能颠倒
    void Cut(int x,int y)
    {
    	if(linked(x,y)&&!ch[y][0])fa[y]=ch[x][1]=0,up(x);
    }
}T;

int main()
{
	
	return 0;
}
