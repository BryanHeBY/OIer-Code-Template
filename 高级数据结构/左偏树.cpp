#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;

struct lp
{
    int val[N],l[N],r[N],d[N];
    int merge(int x,int y)
    {
        if(!x||!y)return x+y;
        if(val[x]>val[y])swap(x,y);
        r[x]=merge(r[x],y);
        if(d[l[x]]<d[r[x]])swap(l[x],r[x]);
        d[x]=d[r[x]]+1;
        return x;
    }
    void pop(int &x){val[x]=-1;x=merge(l[x],r[x]);}
}T;

int main()
{
	
	return 0;
}
