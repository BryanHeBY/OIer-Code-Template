#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;

int x,y,z;
struct fhq_treap
{
	int data[N],fix[N],ch[N][2],size[N],root,cnt;
	void up(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
	int newn(int key){return data[++cnt]=key,fix[cnt]=rand(),ch[cnt][0]=ch[cnt][1]=0,up(cnt),cnt;}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;//down(x),down(y);
		if(fix[x]<fix[y])return ch[x][1]=merge(ch[x][1],y),up(x),x;
		else return ch[y][0]=merge(x,ch[y][0]),up(y),y;
	}
	void split(int now,int val,int &x,int &y)
	{
		if(!now){x=y=0;return;}
		if(data[now]<=val)x=now,split(ch[now][1],val,ch[now][1],y);
		else y=now,split(ch[now][0],val,x,ch[now][0]);
		up(now);
	}
    /*
    void split(int now,int rank,int &x,int &y)
	{
		if(!now){x=y=0;return;}down(now);
		if(size[l[now]]+1<=rank)x=now,split(r[now],rank-(size[l[now]]+1),r[now],y);
		else y=now,split(l[now],rank,x,l[now]);
		up(now);
	}//根据排名拆分
    */
	void insert(int val){split(root,val,x,y);root=merge(merge(x,newn(val)),y);}
	void del(int val)
	{
		split(root,val,x,z),split(x,val-1,x,y);
		root=merge(merge(x,merge(ch[y][0],ch[y][1])),z);
	}
	int grank(int val)
	{
		split(root,val-1,x,y);
		int ans=size[x]+1;root=merge(x,y);
		return ans;
	}
	int Kth(int x,int rank)
	{
		while(233)
		{
			if(rank<=size[ch[x][0]])x=ch[x][0];
			else if(rank<=size[ch[x][0]]+1)return x;
			else rank-=size[ch[x][0]]+1,x=ch[x][1];
		}
	}
	int pren(int val)
	{
		split(root,val-1,x,y);
		int ans=data[Kth(x,size[x])];root=merge(x,y);
		return ans;
	}
	int nextn(int val)
	{
		split(root,val,x,y);
		int ans=data[Kth(y,1)];root=merge(x,y);
		return ans;
	}
}T; 

int main()
{
	
	return 0;
}
