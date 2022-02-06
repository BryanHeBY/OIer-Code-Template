#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;

struct AVL
{
    int root,data[N],cnt[N],ch[N][2],h[N];
    int now;
    #define lc(x) ch[x][0]
    #define rc(x) ch[x][1]
    AVL():root(0),now(0){}
    inline void update(int x){
        h[x]=max(h[lc(x)],h[rc(x)])+1;
    }
    inline void rotateL(int &x){
        int r=rc(x),rl=lc(r);
        rc(x)=rl, lc(r)=x;
        update(x), update(r);
        x=r;
    }
    inline void rotateR(int &x){
        int l=lc(x),lr=rc(l);
        lc(x)=lr, rc(l)=x;
        update(x), update(l);
        x=l;
    }
    inline int getFactor(int x){
        return h[lc(x)]-h[rc(x)];
    }
    inline void Rebalance(int &x){
        int x_factor=getFactor(x);
        int l_factor=getFactor(lc(x)),r_factor=getFactor(rc(x));
        if(x_factor>1 && l_factor>0)rotateR(x);
        else if(x_factor>1 && l_factor<=0)rotateL(lc(x)),rotateR(x);
        else if(x_factor<-1 && r_factor<=0)rotateL(x);
        else if(x_factor<-1 && r_factor>0)rotateR(rc(x)),rotateL(x);
    }

    void insert(int &x,int key){
        if(x==0){
            x=++now;
            data[x]=key,cnt[x]=1;
            return;
        }
        if(key<data[x])insert(lc(x),key);
        else if(key==data[x])cnt[x]++;
        else insert(rc(x),key);
        Rebalance(x);
    }
}T;

int main()
{
	
	return 0;
}
